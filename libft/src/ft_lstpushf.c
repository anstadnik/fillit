/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:39:23 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/09 13:12:57 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds a new element of t_list type at the beginning of the list.
*/

#include "libft.h"

void	ft_lstpushf(t_list **alst, void *content, size_t content_size)
{
	t_list	*rez;

	rez = ft_lstnew(content, content_size);
	if (!alst)
		return ;
	if (*alst)
		rez->next = (*alst);
	*alst = rez;
}
