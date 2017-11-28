/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:21:57 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/28 13:44:09 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns index of point according to given name and index's index
*/

#include "fillit.h"
char	getindex(char n, char i)
{
	char	r;

	r = i == 1 ? n >> 4 : 15 & n;
	return (r >= 0 ? r : r + 16);
}

/*
** Returns char containing 2 indexses
*/

char	setindex(char n1, char n2)
{
	return ((char)(n1 << 4 | (n2 & 15)));
}
