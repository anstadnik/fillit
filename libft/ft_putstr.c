/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:05:43 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/09 13:14:15 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s to the standard output.
*/

#include "libft.h"

void	ft_putstr(char const *str)
{
	if (!str)
		return ;
	while (*str)
		ft_putchar(*str++);
}
