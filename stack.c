/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 20:00:23 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/28 15:32:02 by astadnik         ###   ########.fr       */
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
	if (p->d == p->c)
		temp = ((t_colobj *)p->d)->d;
	else
		temp = (t_point *)p->d;
	while (temp != p)
	{
		if (temp == p->c)
		{
			temp = ((t_colobj *)temp)->d;
			continue ;
		}
		temp2 = temp;
		while ((temp2 = temp2->r) != temp)
		{
			(((t_colobj *)temp2->c)->size)--;
			if (temp2->u == temp2->c)
				((t_colobj *)temp2->u)->d = temp2->d;
			else
				((t_point *)temp2->u)->d = temp2->d;
			if (temp2->d == temp2->c)
				((t_colobj *)temp2->d)->u = temp2->u;
			else
				((t_point *)temp2->d)->u = temp2->u;
		}
		temp = (t_point *)temp->d;
	}
}

char		del(t_point *p, t_filist **rez)
{
	t_point		*temp;
	t_filist	*tmp;

	if (!(tmp = malloc(sizeof(t_filist))))
		return (0);
	tmp->next = *rez;
	tmp->data = p;
	*rez = tmp;
	((t_colobj *)((t_colobj *)p->c)->l)->r = ((t_colobj *)p->c)->r;
	((t_colobj *)((t_colobj *)p->c)->r)->l = ((t_colobj *)p->c)->l;
	temp = p->r;
	while (temp != p)
	{
		hide(temp);
		temp = temp->r;
	}
	return (1);
}

static void	show(t_point *p)
{
	t_point	*temp;
	t_point	*temp2;

	((t_colobj *)((t_colobj *)p->c)->l)->r = p->c;
	((t_colobj *)((t_colobj *)p->c)->r)->l = p->c;
	if (p->u == p->c)
		temp = ((t_colobj *)p->u)->u;
	else
		temp = (t_point *)p->u;
	while (temp != p)
	{
		if (temp == p->c)
		{
			temp = ((t_colobj *)temp)->u;
			continue ;
		}
		temp2 = temp;
		while ((temp2 = temp2->l) != temp)
		{
			((t_colobj *)temp2->c)->size++;
			if (temp2->u == temp2->c)
				((t_colobj *)temp2->u)->d = temp2;
			else
				((t_point *)temp2->u)->d = temp2;
			if (temp2->d == temp2->c)
				((t_colobj *)temp2->d)->u = temp2;
			else
				((t_point *)temp2->d)->u = temp2;
		}
		temp = (t_point *)temp->u;
	}
}

void		restore(t_filist **rez)
{
	t_point		*p;
	t_point		*te;
	t_filist	*temp;

	p = (*rez)->data;
	temp = (*rez)->next;
	free(*rez);
	*rez = temp;
	te = p->l;
	while (te != p)
	{
		show(te);
		te = te->l;
	}
	((t_colobj *)((t_colobj *)p->c)->l)->r = p->c;
	((t_colobj *)((t_colobj *)p->c)->r)->l = p->c;
}
