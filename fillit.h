/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:23:37 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/19 17:59:58 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

/*
** initializing struct for check.c, which will obviously check the input,
** count num of tetriminos, and will determine the size of the square.
*/

typedef	struct	s_params
{
	char	size_of_sq;
	char	amount;
}				t_params;

#endif
