/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:34:33 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/22 16:45:42 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	printcol(t_colobj *head)
{
	t_colobj	*ptr;

	putchar(head->n);
	putstr("  ");
	col = head->r;
	while (col != void(head))
	{
		putnbr(getindex(col->n), 1);
		putnbr(getindex(col->n), 2);
		putstr(" ");
		col = col->r;
	}
	putchar("\n");
	putstr("   ");
	while (col != void(head))
	{
		putnbr(col->size);
		putstr("  ");
	}
	putchar("\n");
}

void	visualize(t_colobj *head)
{
	t_colobj	*col;
	t_point		*rowh;
	t_point		*cur;
	t_colobj	*temp;

	printcol(head);
	col = head->r;
	while (col->n != 17)
	{//go through colums 'A', 'B' etc
		rowh = col->d;
		while (rowh != col)
		{//go down through one's
			temp = (t_colobj)head->r;
			putstr("   ");
			cur = rowh;
			while (temp != head)
			{
				if (cur->c == temp)
				{
					putstr("1  ");
					cur = (t_colobj)cur->r;
				}
				else
					putstr("   ");
				temp = (t_colobj)temp->r;
			}
			rowh = rowh->d;
		}
		col = col->r;
	}
}
