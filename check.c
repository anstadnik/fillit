/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:31:30 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/20 20:18:06 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/stat.h>
#include <sys/types.h>

/*
** It's the first step of checking our input. It checks whether all symbols 
** in file are appropriate.
*/

int		first_check(char *buf)
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

int		check_T(char *buf, int count)
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

int		second_check_n_count(char *buf, t_params **params, int *T_tet)
{
	int count;
	int	t_count;

	count = 0;
	t_count = 0;
	while (buf[count])
	{
		if (buf[count] == '#')
		{
			if (check_T(buf, count))
			{	
				(*T_tet)++;
				ft_putnbr(*T_tet);
				ft_putchar('\n');
			}
			if ((buf[count + 1] == '#' || buf[count + 5] == '#') && count == 0)
				t_count++;
			else if ((buf[count - 1] == '#' || buf[count + 1] == '#' 
					|| buf[count + 5] == '#') && count < 4)
				t_count++;
			else if	(buf[count + 1] == '#' || buf[count - 1] == '#' 
					|| buf[count + 5] == '#' || buf[count - 5] == '#')
				t_count++;
		}
		count++;
	}
//	if (t_count != 4)
//		return (0);
	(*params)->amount++;
	return (t_count != 4) ? 0 : 1;
//	return (1);
}

t_params	*check(char *str)
{
	t_params *params;
	char buf[21];
	int fd;
	int	T_tet;
	int ret;

	T_tet = 0;
	params = (t_params *)malloc(sizeof(t_params));
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	params->amount = 0;
	while ((ret = read(fd, &buf, 21)))
		if (!first_check(buf) || (!second_check_n_count(buf, &params, &T_tet)))
			return (NULL);
	close(fd);
	return (params);
}

int		main(int argc, char **argv)
{
	t_params	*tmp;
	tmp = check(argv[argc - 1]);
	if (tmp == NULL) 
	{
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	ft_putnbr((int)tmp->amount);
	return (0);
}
