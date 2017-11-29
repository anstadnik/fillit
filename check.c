/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:31:30 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/29 18:37:43 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/stat.h>
#include <sys/types.h>

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
** This func checks whether the tetrimino is T_shaped.
*/

int		check_t(char *buf, int count)
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

/*
** Second step of checking. It checks tetriminos themselves.
** Also, function counts the number of tetriminos
*/

static	int		second_check_n_count(char *buf, t_params *params, int *t_tet)
{
	int count;
	int	t_count;

	count = 0;
	t_count = 1;
	while (buf[count])
	{
		if (!(buf[count] == '.' || buf[count] == '#' || buf[count] == '\n'))
			return (0);
		if (buf[count] == '#')
		{
			if (check_t(buf, count))
				(*t_tet)++;
			if ((buf[count + 1] == '#' && buf[count + 2] == '#' && buf[count + 3] == '#') 
					|| (buf[count + 5] == '#' && buf[count + 10] == '#' && buf[count + 15] == '#'))
				params->max_l = 4;
			if (buf[count + 1] == '#')
				t_count++;
			if (buf[count + 5] == '#')
				t_count++;
			if (buf[count - 1] == '#')
				t_count++;
			if (buf[count - 5] == '#')
				t_count++;
		}	
		count++;
		if ((!((count + 1) % 5) || count == 20) && buf[count] != '\n')
			return (0);
	}
/*	ft_putendl("max_l = ");
	ft_putnbr(params->max_l);
	ft_putchar('\n');
	*/
	params->amount++;
	return (t_count < 6) ? 0 : 1;
}

/*
** It calculates the size of the square according to the given number of
** tetriminos. It pays attention to t_shaped tetriminos.
*/

static	void	count_size_of_sq(t_params *params, int t_tet)
{
	if (t_tet % 2)
		params->size = ft_sqrt((params->amount) * 4 + 2);
	else
		params->size = ft_sqrt(4 * params->amount);
	if (params->size < params->max_l)
		params->size = params->max_l;
}

/*
** Checkings, checkings and more of them.
*/

t_params		*check(char *str)
{
	char	buf[22];
	int		fd;
	int		t_tet;
	int		ret;
	t_params	*params;

	t_tet = 0;
	if (!(params = (t_params *)malloc(sizeof(t_params))) || 
				(fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	params->amount = 0;
	params->max_l = 0;
	while ((ret = read(fd, &buf, 21)))
	{
		if (ret < 20 || ret > 21 || !second_check_n_count(buf, params, &t_tet))
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
