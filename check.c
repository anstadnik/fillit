/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:31:30 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/19 20:36:45 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int		check_n_count(char *buf, t_params **params)
{



t_params	*check(char *str)
{
	t_params *params;
	char buf[21];
	int fd;

	lol = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, &buf, 21))
		if (!check_n_count(&buf, &params))
			return (NULL);
	return (params);
}

int		main(int argc, char **argv)
{
	if (!check(argv[argc - 1]))
		ft_putendl("lol");
	return (0);
}
