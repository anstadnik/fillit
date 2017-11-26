/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:36:43 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/26 17:26:47 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	restore(t_colobj *head, t_list **rez)
{
	while (*rez->next)
		rez = &(rez->next);
	//restore
	
	free(*rez->next);
	*rez->next = NULL;
}

static char	solverec(char *sol, t_colobj *head, t_colobj *cur, t_point *rez)
{
	t_point	*p;
	char	f;

	f = 0;
	p = cur->d;
	while (p != cur)
	{
		if (!delete(head, p, &rez))
		{
			ft_lstdel(&rez);
			return (2);
		}
		if (check(head))
		{
			if (cur->l == head && f ? f : ++f)
				fillsol(sol, rez);
			else
				if (solverec(sol, head, cur->l, rez) == 2)
					return (2);
		}
		restore(head, p, &rez);
		p = p->d;
	}
	return (f);
}

char	solve(char **sol, t_colobj *head, char size)
{
	t_colobj	*cur;
	t_list		*rez;
	char		r;

	free(*sol);
	sol = NULL;
	if (!(*sol = malloc(sizeof(char) * size * size)))
		return (2);
	//null sol
	rez = NULL;
	cur = (t_colobj)head->r;
	while (((t_colobj *)cur->r)->n != 17)
		cur = ((t_colobj *)cur->r);
	r = solverec(*sol, head, cur, rez);
	free(cur);
	return (r);
}

