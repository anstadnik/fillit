/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:36:43 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/26 18:53:14 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Hides the row
*/

static void	hide(t_point *p)
{
	t_point	*temp;
	t_point	*temp2;

	((t_colobj *)((t_colobj *)p->c)->l)->r = ((t_colobj *)p->c)->r;
	((t_colobj *)((t_colobj *)p->c)->r)->l = ((t_colobj *)p->c)->l;
	temp = (t_point *)p->d;
	while (temp != p)
	{
		if (temp == p->c)
		{
			temp = (t_colobj *)temp->d;
			continue ;
		}
		temp2 = temp;
		while ((temp2 = temp2->r) != temp)
		{
			//check for col
			((t_colobj *)temp2->c)->size--;
			if (temp2->u == temp2->c)
				((t_colobj *)temp2->u)->d = temp2->d;
			else
				((t_point *)temp2->u)->d = temp2->d;
			if (temp2->u == temp2->c)
				((t_colobj *)temp2->d)->u = temp2->u;
			else
				((t_point *)temp2->d)->u = temp2->u;
			temp2->d->u = temp2->u;
		}
		temp = (t_point *)temp->d;
	}
}

static char	delete(t_point *p, t_filist **rez)
{
	t_point	*temp;
	t_point	*temp2;

	while (*rez)
		rez = &(*rez->next);
	if (!(*rez = malloc(sizeof(t_filist))))
		return (0);
	rez->data = p;
	hide(p);
	temp = p->r;
	while (temp != p)
	{
		hide(temp);
		temp = temp->r;
	}
	return (1);
}

static char	solverec(char *sol, t_colobj *head, t_colobj *cur, t_point *rez)
{
	t_point	*p;
	char	f;

	f = 0;
	p = cur->d;
	while (p != cur)
	{
		if (!delete(p, &rez))
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
		restore(&rez);
		p = p->d;
	}
	return (f);
}

char	solve(char **sol, t_colobj *head, char size)
{
	t_colobj	*cur;
	t_filist		*rez;
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

