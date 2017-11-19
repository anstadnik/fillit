/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:23:42 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/12 15:36:04 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the last element from the list
*/

#include "libft.h"

t_list	*ft_lstgetlast(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
