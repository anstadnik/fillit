/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:34:33 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/24 13:00:30 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	printsize(t_colobj *head)
{
	t_colobj	*ptr;

	ft_putstr("   ");
	ptr = head->r;
	while (ptr != head)
	{
		ft_putnbr(ptr->size);
		ft_putstr("  ");
		ptr = ptr->r;
	}
	ft_putchar('\n');
}

static void	printcol(t_colobj *head, char fl)
{
	t_colobj	*ptr;
	char		f;

	f = 0;
	ptr = head;
	while (42)
	{
		if (ptr->n == 17)
			f = 1;
		if (f)
		{
			ft_putnbr(getindex(ptr->n, 1));
			ft_putnbr(getindex(ptr->n, 2));
		}
		else
			ft_putchar(ptr->n);
		ft_putstr(f ? " " : "  ");
		if ((ptr = ptr->r) == head)
			break ;
	}
	ft_putchar('\n');
	if (fl)
		printsize(head);
}

void		visualize(t_colobj *head, char fl)
{
	t_colobj	*col;
	t_point		*rowh;
	t_colobj	*temp;

	printcol(head, fl);
	col = head->r;
	while (col->n != 17)
	{
		rowh = col->d;
		while ((void *)rowh != (void *)col)
		{
			temp = (t_colobj *)head->r;
			ft_putstr("   ");
			while (temp != head)
			{
				ft_putstr(rowh->c == temp ? "1  " : "   ");
				rowh = rowh->c == temp ? (t_point *)rowh->r : rowh;
				temp = (t_colobj *)temp->r;
			}
			ft_putchar('\n');
			rowh = rowh->d;
		}
		col = col->r;
		printcol(head, fl);
	}
}
