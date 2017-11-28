/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:36:43 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/28 09:50:26 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char check(t_colobj *head)
{
	t_colobj *tmp;

	tmp = (t_colobj *)head->r;
	while (tmp != head)
	{
		if (tmp->size > 1)
			return (0);
		tmp = (t_colobj *)tmp->r;
	}
	return (1);
}

static void filist_del(t_filist **rez)
{
	t_filist *tmp;
	t_filist *next;

	tmp = *rez;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

/*
** Recursively searches for solutions
*/

static void	fillsol(char *sol, t_filist *rez, char size)
{
	unsigned char	i;
	char			temp[size * size];
	unsigned char	n;
	t_point			*tmp;

	ft_putstr("potato");
	i = (unsigned char)size * (unsigned char)size + 1;
	while (i--)
		temp[i] = ' ';
	while (rez)
	{
		n = (unsigned char)((t_colobj *)rez->data->c)->n;
		tmp = rez->data->r;
		while (tmp != rez->data)
			temp[(getindex(((t_colobj *)tmp->c)->n, 1) - 1) * size +
				getindex(((t_colobj *)tmp->c)->n, 1)] = n;
		rez = rez->next;
	}
	i = 'A' - 1;
	while (++i <= 'Z' && (i == 'A' || temp[n] != sol[n + 1]))
	{
		n = 0;
		while (sol[n + 1] != i && temp[n] != i)
			n++;
	}
	i = size * size + 1;
	if (!sol[1] || temp[n] == --i)
		while (--i)
			sol[i] = temp[i - 1];
}

static char	solverec(char size, t_colobj *head, t_colobj *last, t_filist **rez)
{
	t_point		*p;
	t_colobj	*cur;

	f = 0;
	cur = head->r;
	p = cur->d;
	while ((void *)p != (void *)last)
	{
		if (!del(p, rez))
		{
			filist_del(rez);
			return (2);
		}
		if (check(head))
		{
			if (cur == last)
			{
				print(*rez, size);
				return (1);
			}
			else if (solverec(sol, head, last->r, rez) == 2)
				return (2);
		}
		restore(rez);
		p = p->d;
	}
	return (0);
}

/*
** Prepares vars for solverec
*/

char	solve(char **sol, t_colobj *head, char size)
{
	t_colobj			*last;
	t_filist			*rez;
	unsigned char		r;

	if (!(*sol = malloc(sizeof(char) * size * size + 2)))
		return (2);
	r = size * size + 1;
	while (--r)
		(*sol)[r] = ' ';
	(*sol)[0] = size;
	(*sol)[size * size + 1] = '\0';
	rez = NULL;
	last = (t_colobj *)head->r;
	while (((t_colobj *)last->r)->n != 17)
		last = ((t_colobj *)last->r);
	r = solverec(*sol, head, last, &rez);
	if (r != 1)
		free(*sol);
	free(last);
	return (r);
}
