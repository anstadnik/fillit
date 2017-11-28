/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createsheet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:59:22 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/25 20:21:20 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates new sheet
*/

#include "fillit.h"

/*
** Makes head obj, and fills it's pointers. So far there is only
** head obj in sheet
*/

static t_colobj	*makehead(void)
{
	t_colobj	*head;

	head = malloc(sizeof(t_colobj));
	if (!head)
		return (NULL);
	head->u = NULL;
	head->d = NULL;
	head->r = head;
	head->l = head;
	head->n = 'h';
	head->size = 0;
	return (head);
}

/*
** This function adds new column to the sheet and fills it's pointers.
*/

static char		fillcol(t_colobj *head, char n)
{
	t_colobj	*temp;

	if (!(temp = malloc(sizeof(t_colobj))))
		return (0);
	temp->r = head;
	temp->l = head->l;
	temp->u = temp;
	temp->d = temp;
	temp->n = n;
	temp->size = 0;
	((t_colobj *)head->l)->r = temp;
	head->l = temp;
	return (1);
}

/*
** Makes column objects. This function is responsible for calling fillcol and
** giving it correct name.
*/

static char		makecol(t_colobj *head, char am, char size)
{
	char		n;

	n = 'A';
	while (am > 0 || getindex(n, 1) != size + 1)
	{
		if (!fillcol(head, n))
			return (0);
		am = am == -1 ? am : am - 1;
		if (am > 0)
			n++;
		else
			n = getindex(n, 2) == size ? setindex(getindex(n, 1) + 1, 1) :
					setindex(getindex(n, 1), getindex(n, 2) + 1);
		n = am ? n : 17;
	}
	return (1);
}

/*
** Checks inputs, opens file, then makes head, columns and fills ones.
*/

t_colobj		*createsheet(t_params params, char *path)
{
	t_colobj	*head;
	int			fd;

	fd = -1;
	head = NULL;
	if (!path || !params.amount || !params.size
			|| (fd = open(path, O_RDONLY)) == -1
			|| !(head = makehead())
			|| !makecol(head, params.amount, params.size)
			|| !fillsheet(head, fd, params.size))
	{
		cleansheet(&head);
		if (fd != -1)
			close(fd);
		return (NULL);
	}
	return (head);
}
