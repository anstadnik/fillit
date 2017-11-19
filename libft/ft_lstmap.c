/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:38:59 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/09 13:13:52 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the successive
** applications of f. If the allocation fails, the function
** returns NULL.
*/

static void	r(void *ptr, size_t size)
{
	if (size)
		free(ptr);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rez;
	t_list	*temp;

	rez = NULL;
	while (lst)
	{
		if (!(temp = f(lst)))
		{
			ft_lstdel(&rez, &r);
			return (NULL);
		}
		ft_lstaddb(&rez, temp);
		lst = lst->next;
	}
	return (rez);
}
