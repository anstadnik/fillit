/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:34:33 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/28 12:14:00 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print(t_filist *rez, char size)
{
	unsigned char	i;
	unsigned char	n;
	char			sol[size * size];
	t_point			*tmp;

	i = (unsigned char)size * (unsigned char)size + 1;
	while (i--)
		sol[i] = '.';
	while (rez)
	{
		n = (unsigned char)((t_colobj *)rez->data->c)->n;
		/*
		ft_putendl("");
		ft_putchar(n);
		ft_putendl("");
		*/
		tmp = rez->data->r;
		while (tmp != rez->data)
		{
		/*
		ft_putendl("");
		ft_putchar(n);
		ft_putchar(' ');
		ft_putnbr(getindex(((t_colobj *)tmp->c)->n, 1));
		ft_putchar(' ');
		ft_putnbr(getindex(((t_colobj *)tmp->c)->n, 2));
		ft_putendl("");
		*/
			sol[(getindex(((t_colobj *)tmp->c)->n, 1) - 1) * size +
				getindex(((t_colobj *)tmp->c)->n, 2) - 1] = n;
			tmp = tmp->r;
		}
		rez = rez->next;
	}

	i = 0;
	while (i < size * size)
	{
		ft_putchar(sol[i]);
		if (!(++i % size))
			ft_putchar('\n');
	}
}

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

static void	printcol(t_colobj *head, char f1)
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
	if (f1)
		printsize(head);
}

void		visualize(t_colobj *head, char f1, char f2, t_colobj *last)
{
	t_colobj	*col;
	t_point		*rowh;
	t_colobj	*temp;

	printcol(head, f1);
	col = head->r;
	while (last ? (col->l != last) : col->n != 17)
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
		if (f2)
			printcol(head, f1);
	}
}
