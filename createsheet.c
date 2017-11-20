/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createsheet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:59:22 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/20 18:19:58 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates new sheet
*/

#include "fillit.h"

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
static char		makecol(t_colobj *head, char am, char size)
{
	t_colobj	*temp;
	char		n;

	n = 'A';
	while (1)
	{
		if (!temp = malloc(sizeof(t_colobj)))
		{
			cleansheet(&head);
			return (0);
		}
		temp->r = head;
		temp->l = head->l;
		temp->u = temp;
		temp->d = temp;
		temp->n = n;
		temp->s = 0;
		((t_colobj)head->l)->r = temp;
		head->l = temp;
		if (am-- > 0)
			n++;
		else if (getindex(n, 1) == size && getindex(n, 2) == size)
				return (1);
			else if (am == -1)
					n = 0;
				else
					n = getindex(n, 1) == size ? 16 | getindex(n, 2) + 1 :
						(getindex(n, 1) + 1) << 4 & getindex(n, 2);
	}
}
*/
t_colobj		*createsheet(t_params params, char *path)
{
	t_colobj	*head;
	int			fd;

	if (!path || fd = open(path, O_RDONLY) != -1
			|| !head = makehead()
			|| !makecol(head, params.amount, params.size)
			|| !fillsheet(head, fd))
		return (NULL);
	return (head);
}
