/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:11:28 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/23 19:23:20 by lburlach         ###   ########.fr       */
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
	while (i * i <= num)
	{
		if (i * i == num)
			return (i);
		i++;
	}
	return (i);
}

/*
** This func checks whether the tetrimino is T_shaped.
*/

int		check_t(char *buf, int count)
{
	if ((count < 12) && (buf[count + 5] == '#' && (buf[count + 6] == '#'
				|| buf[count + 4] == '#') && buf[count + 10] == '#'))
		return (1);
	else if ((count < 16) && (buf[count + 1] == '#' && buf[count + 2] == '#'
				&& buf[count + 6] == '#'))
		return (1);
	else if ((count < 16) && (buf[count + 4] == '#' && buf[count + 5] == '#'
				&& buf[count + 6] == '#'))
		return (1);
	else
		return (0);
}
