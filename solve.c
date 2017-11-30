/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:36:43 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/29 18:59:04 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	check_h(t_colobj *head, t_colobj *last)
{
	t_colobj *tmp;

	tmp = (t_colobj *)head->r;
	while (tmp != last->r)
	{
		if (tmp->size == 0)
			return (0);
		tmp = (t_colobj *)tmp->r;
	}
	return (1);
}

static void	filist_del(t_filist **rez)
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

static char	solverec(char size, t_colobj *head, t_colobj *last, t_filist **rez)
{
	t_point		*p;
	t_colobj	*cur;
	char		r;

	cur = head->r;
	p = cur->d;
	while ((void *)p != (void *)cur)
	{
		if (!del(p, rez))
		{
			filist_del(rez);
			return (1);
		}
		if (cur == last)
		{
			print(*rez, size);
			return (1);
		}
		if (check_h(head, last))
			if ((r = solverec(size, head, last, rez)))
				return (r);
		restore(rez);
		p = p->d;
	}
	return (0);
}

/*
** Prepares vars for solverec
*/

char		solve(t_colobj *head, char size)
{
	t_colobj			*last;
	t_filist			*rez;

	rez = NULL;
	last = (t_colobj *)head->r;
	while (((t_colobj *)last->r)->n != 17)
		last = ((t_colobj *)last->r);
	return (solverec(size, head, last, &rez));
}
