/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillsheet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:05:06 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/22 16:54:45 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Fills pos arr with tetramino's coordinates
*/

static void	fillpos(char buf[21], char *pos, char size)
{
	char			offs;
	unsigned char	i;
	unsigned char	j;

	j = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (!j)
				offs = setindex(i / (size + 1), i % (size + 1));
			pos[j++] = setindex(i / (size + 1) - getindex(offs, 1) + 1, i % (size + 1) - getindex(offs, 2) + 1);
		}
		i++;
	}	
}

/*
** Increments pos. If it goes out of bondary, it returns 0, otherwise it's 1.
*/

static char	incpos(char *pos, char size)
{
	unsigned char	i;
	unsigned char	f;

	f = 0;
	i = 0;
	while (i < 4)
		if (getindex(pos[i++], 2) + 1 > size)
			f = 1;	
	i = 0;
	while (i < 4)
		if (f)
			pos[i] = setindex(getindex(pos[i], 1) + 1, getindex(pos[i], 2) - getindex(pos[0], 2) - 1);
		else
			pos[i] = setindex(getindex(pos[i], 1), getindex(pos[i], 2) + 1);
	i = 0;
	while (i < 4)
		if (getindex(pos[i], 1) > size)
			return (0);
	return (1);
}

static t_point	*addone(t_colobj *col, t_point *rowh)
{
	t_point	*one;

	if (!(one = malloc(sizeof(t_point))))
		return (NULL);
	if (!rowh)
	{
		one->l = one;
		one->r = one;
	}
	else
	{
		one->r = rowh;
		one->l = rowh->l;
		((t_point *)rowh->l)->r = one;
		rowh->l = one;
	}
	one->u = col->u;
	one->d = col;
	one->c = col;
	if (col->u == col)
		col->d = one;
	else
		((t_point *)col->u)->d = one;
	col->u = one;
	return (one);
}

/*
** Adds new row to the sheet
*/

static char	addones(t_colobj *head, char n, char *pos)
{
	t_point		*first;
	t_colobj	*cur;
	char		i;

	i = -1;
	cur = head;
	while (++i < 5)
	{
		cur = (t_colobj *)cur->r;
		if (!i)
		{
			if (cur->n == n)
			{
				if (!(first = addone(cur, NULL)))
					return (0);
				i++;
			}
		}
		else
			if (cur->n == pos[i++ - 1])
				if (!addone(cur, first))
					return (0);
	}		
}

/*
** Fills sheet with "ones"
*/

char	fillsheet(t_colobj *head, int fd, char size)
{
	char	buf[22];
	char	*pos;
	char	cur;

	buf[21] = '\0';
	if (!(pos = malloc(sizeof(char) * 5)))
		return (0);
	pos[4] = '\0';
	cur = 'A';
	read(fd, buf, 21);
	while (42)
	{
		fillpos(buf, pos, size);
		while (incpos(pos, size))
			if (!addones(head, cur, pos))
				return (0);
		cur++;
		if (!read(fd, buf, 21))
			return (1);
	}
}
