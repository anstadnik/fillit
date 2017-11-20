/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getindex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:40:27 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/20 15:44:03 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns index of point according to given name and index's index
*/

char	getindex(char n, char i)
{
	return (i == 1 ? n >> 4 : 15 & n);
}
