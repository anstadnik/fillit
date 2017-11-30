/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:31:30 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/30 20:32:28 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/stat.h>
#include <sys/types.h>

/*
** This func checks whether the tetrimino is T_shaped.
*/

int				check_t(char *buf, int count)
{
	if ((count < 11) && (buf[count + 5] == '#' && (buf[count + 6] == '#'
				|| buf[count + 4] == '#') && buf[count + 10] == '#'))
		return (1);
	else if ((count < 15) && (buf[count + 1] == '#' && buf[count + 2] == '#'
				&& buf[count + 6] == '#'))
		return (1);
	else if ((count < 15) && (buf[count + 4] == '#' && buf[count + 5] == '#'
				&& buf[count + 6] == '#'))
		return (1);
	else
		return (0);
}

static char		minsize(char first, char last, char size)
{
	char		max;

	max = (last + 1) % 5 - getindex(first, 2);
	max = max > 0 ? max : -max;
	max = (max > (last + 1) / 5 - getindex(first, 1) ?
		max + 1 : (last + 1) / 5 - getindex(first, 1) + 1);
	return (max > size ? max : size);
}

/*
** Second step of checking. It checks tetriminos themselves.
** Also, function counts the number of tetriminos
*/

static	int		check_n_count(char *buf, t_params *params, int *t_tet)
{
	int			count;
	int			t_count;
	int			r;
	char		first;

	count = -1;
	t_count = 0;
	r = 0;
	while (buf[++count])
		if (buf[count] == '#')
		{
			if (!r++)
				first = setindex((count + 1) / 5, (count + 1) % 5);
			if (r == 4)
				params->size = minsize(first, count, params->size);
			if (check_t(buf, count))
				(*t_tet)++;
			t_count += (buf[count + 1] == '#') + (buf[count + 5] == '#') +
				(buf[count - 1] == '#') + (buf[count - 5] == '#');
		}
		else if (!(buf[count] == '.' || buf[count] == '\n') ||
			((!((count + 1) % 5) || count == 20) && buf[count] != '\n'))
			return (0);
	params->amount++;
	return ((t_count < 5) || r != 4) ? 0 : 1;
}

/*
** It calculates the size of the square according to the given number of
** tetriminos. It pays attention to t_shaped tetriminos.
*/

static	void	count_size_of_sq(t_params *params, int t_tet)
{
	char		size;

	if (t_tet % 2)
		size = ft_sqrt((params->amount) * 4 + 2);
	else
		size = ft_sqrt(4 * params->amount);
	params->size = params->size > size ? params->size : size;
}

/*
** Checkings, checkings and more of them.
*/

t_params		*check(char *str)
{
	char		buf[22];
	int			fd;
	int			t_tet;
	int			ret;
	t_params	*params;

	t_tet = 0;
	if (!(params = (t_params *)malloc(sizeof(t_params))) ||
				(fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	params->amount = 0;
	params->size = 0;
	buf[20] = '\n';
	while ((ret = read(fd, &buf, 21)))
	{
		if (ret < 20 || ret > 21 || !check_n_count(buf, params, &t_tet))
			return (NULL);
		if (ret == 20)
			break ;
	}
	close(fd);
	count_size_of_sq(params, t_tet);
	if (ret != 20)
		free(params);
	return (ret == 20 ? params : NULL);
}
