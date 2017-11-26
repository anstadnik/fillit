/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:36:43 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/26 21:06:08 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Recursively searches for solutions
*/

static void	fillsol(char *sol, t_filist *rez, char size)
{
	char	i;
	char	temp[size * size];
	char	n;
	t_point	*tmp;

	i = size * size + 1;
	while (i--)
		temp[i] = ' ';
	while (rez)
	{
		n = ((t_colobj *)rez->data->c)->n;
		tmp = rez->data->r;
		while (tmp != rez->data)
			temp[(getindex(((t_colobj *)tmp->c)->n, 1) - 1) * size +
				getindex(((t_colobj *)tmp->c)->n, 1)] = n;
		rez = rez->next;
	}
	i = 'A' - 1;
	while (++i <= 'Z' && (i == 'A' || temp[n] != i[n + 1]))
	{
		n = 0;
		while (i[n + 1] != i && temp[n] != i)
			n++;
	}
	i = size * size + 1;
	if (!sol[1] || temp[n] == --i)
		while (--i)
			sol[i] = temp[i - 1];
}

static char	solverec(char *sol, t_colobj *head, t_colobj *cur, t_filist *rez)
{
	t_point	*p;
	char	f;

	f = 0;
	p = cur->d;
	while (p != cur)
	{
		if (!del(p, &rez))
		{
			ft_lstdel(&rez);
			return (2);
		}
		if (check(head))
		{
			if (cur->l == head && f ? f : ++f)
				fillsol(sol, rez, sol[0]);
			else if (solverec(sol, head, cur->l, rez) == 2)
				return (2);
		}
		restore(&rez);
		p = p->d;
	}
	return (f);
}

/*
** Prepares vars for solverec
*/

char	solve(char **sol, t_colobj *head, char size)
{
	t_colobj	*cur;
	t_filist	*rez;
	char		r;

	free(*sol);
	sol = NULL;
	if (!(*sol = malloc(sizeof(char) * size * size + 2)))
		return (2);
	r = size * size + 1;
	while (--r)
		sol[r] = ' ';
	sol[0] = size;
	sol[size * size + 1] = '\0';
	rez = NULL;
	cur = (t_colobj)head->r;
	while (((t_colobj *)cur->r)->n != 17)
		cur = ((t_colobj *)cur->r);
	r = solverec(*sol, head, cur, rez);
	free(cur);
	return (r);
}

