/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:31:30 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/25 21:04:49 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/stat.h>
#include <sys/types.h>

/*
** It's the first step of checking our input. It checks whether all symbols
** in file are appropriate.
*/

static	int		first_check(char *buf)
{
	int count;
	int t_count;

	count = 0;
	t_count = 0;
	if (ft_strlen(buf) != 21)
		return (0);
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n'
			|| buf[19] != '\n' || buf[20] != '\n')
		return (0);
	while (1)
	{
		if (count == 21)
			break ;
		if (!(buf[count] == '.' || buf[count] == '#' || buf[count] == '\n'))
			return (0);
		if (buf[count] == '#')
			t_count++;
		count++;
	}
	if (t_count != 4)
		return (0);
	return (1);
}

/*
** Second step of checking. It checks tetriminos themselves.
** Also, function counts the number of tetriminos
*/

static	int		second_check_n_count(char *buf, t_params **params, int *t_tet)
{
	int count;
	int	t_count;

	count = 0;
	t_count = 0;
	while (buf[count])
	{
		if (buf[count] == '#')
		{
			if (check_t(buf, count))
				(*t_tet)++;
			if ((buf[count + 1] == '#' || buf[count + 5] == '#') && count == 0)
				t_count++;
			else if ((buf[count - 1] == '#' || buf[count + 1] == '#'
					|| buf[count + 5] == '#') && count < 4)
				t_count++;
			else if (buf[count + 1] == '#' || buf[count - 1] == '#'
					|| buf[count + 5] == '#' || buf[count - 5] == '#')
				t_count++;
		}
		count++;
	}
	(*params)->amount++;
	return (t_count != 4) ? 0 : 1;
}

/*
** It calculates the size of the square according to the given number of
** tetriminos. It pays attention to t_shaped tetriminos.
*/

static	void	count_size_of_sq(t_params **params, int t_tet)
{
	if (t_tet % 2 == 1)
		(*params)->size = ft_sqrt(((*params)->amount) * 4 + 2);
	else
		(*params)->size = 2 * ft_sqrt((*params)->amount);
}

/*
** Checkings, checkings and more of them.
*/

static	int		fl_read(t_params **params, char *str)
{
	char	buf[22];
	int		fd;
	int		t_tet;
	int		ret;
	int		flag;

	t_tet = 0;
	flag = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (1);
	(*params)->amount = 0;
	while ((ret = read(fd, &buf, 21)))
	{
		if (ret < 20 || ret > 21)
			return (1);
		if (!first_check(buf) || (!second_check_n_count(buf, params, &t_tet)))
			return (1);
		if (ret == 20)
			flag++;
	}
	if (flag != 1)
		return (1);
	close(fd);
	ft_putstr("t_tet = ");
	ft_putnbr(t_tet);
	ft_putchar('\n');
	count_size_of_sq(params, t_tet);
	return (0);
}

/*
** Had to create this func because of norm's constrictions.
*/

t_params		*check(char *str)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (!params || fl_read(&params, str))
		return (NULL);
	else
		return (params);
}
