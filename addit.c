/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:02:01 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/30 19:05:45 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** It simply search the square root of the give number. Returns bigger root
** than needed in case it can't find precise answer.
*/

int		ft_sqrt(int num)
{
	int i;

	i = 0;
	if (num < 0)
		return (0);
	while (i * i < num)
		i++;
	return (i);
}

/*
** Returns index of point according to given name and index's index
*/

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
