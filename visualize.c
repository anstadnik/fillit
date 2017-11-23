/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:34:33 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/23 17:32:18 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	printcol(t_colobj *head)
{
	t_colobj	*ptr;
	char		f;

	f = 0;
	ft_putchar(head->n);
	ft_putstr("  ");
	ptr = head->r;
	while (ptr != head)
	{
		if (ptr->n == 17)
			f = 1;
		if (f)
		{
			ft_putnbr(getindex(ptr->n, 1));
			ft_putnbr(getindex(ptr->n, 2));
			ft_putstr(" ");
		}
		else
		{
			ft_putchar(ptr->n);
			ft_putstr("  ");
		}
		ptr = ptr->r;
	}
	ft_putchar('\n');
	ft_putstr("   ");
	ptr = ptr->r;
	while (ptr != head)
	{
		ft_putnbr(ptr->size);
		ft_putstr("  ");
		ptr = ptr->r;
	}
	ft_putchar('\n');
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
		while ((void *)rowh != (void *)col)
		{//go down through one's
			temp = (t_colobj *)head->r;
			ft_putstr("   ");
			cur = rowh;
			while (temp != head)
			{
				if (cur->c == temp)
				{
					ft_putstr("1  ");
					cur = (t_point *)cur->r;
				}
				else
					ft_putstr("   ");
				temp = (t_colobj *)temp->r;
			}
			ft_putchar('\n');
			rowh = rowh->d;
		}
		col = col->r;
	}
}
