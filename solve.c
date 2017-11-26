/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:36:43 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/26 19:57:20 by astadnik         ###   ########.fr       */
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
			((t_colobj *)temp2->c)->size--;
			if (temp2->u == temp2->c)
				((t_colobj *)temp2->u)->d = temp2->d;
			else
				((t_point *)temp2->u)->d = temp2->d;
			if (temp2->u == temp2->c)
				((t_colobj *)temp2->d)->u = temp2->u;
			else
				((t_point *)temp2->d)->u = temp2->u;
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

static void	show(t_point *p)
{
	p->c->l->r = p->c;
	p->c->r->l = p->c;
	temp = (t_point *)p->u;
	while (temp != p)
	{
		if (temp == p->c)
		{
			temp = (t_colobj *)temp->u;
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
			if (temp2->u == temp2->c)
				((t_colobj *)temp2->d)->u = temp2;
			else
				((t_point *)temp2->d)->u = temp2;
		}
		temp = (t_point *)temp->u;
	}
}

static void	restore(t_filist **rez)
{
	t_point		*p;
	t_point		*te;
	t_filist	*temp;

	p = *rez->data;
	temp = *rez->next;
	free(*rez);
	*rez = temp;
	te = p->l;
	while (te != p)
	{
		show(te);
		te = te->l;
	}
	show(p);
}

/*
** Recursively searches for solutions
*/

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
		//potato
			ft_lstdel(&rez);
			return (2);
		}
		//potato
		if (check(head))
		{
			if (cur->l == head && f ? f : ++f)
		//potato
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
	if (!(*sol = malloc(sizeof(char) * size * size)))
		return (2);
	rez = NULL;
	cur = (t_colobj)head->r;
	while (((t_colobj *)cur->r)->n != 17)
		cur = ((t_colobj *)cur->r);
	r = solverec(*sol, head, cur, rez);
	free(cur);
	return (r);
}

