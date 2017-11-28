/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:21:57 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/25 20:07:03 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns index of point according to given name and index's index
*/

#include "fillit.h"

char	getindex(char n, char i)
{
	return (i == 1 ? (unsigned char)n >> 4 : 15 & n);
}

/*
** Returns char containing 2 indexses
*/

char	setindex(char n1, char n2)
{
	return ((char)(n1 << 4 | (n2 & 15)));
}
