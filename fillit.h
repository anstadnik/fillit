/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:23:37 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/23 19:27:21 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

/*
** Defining a struct which will contain the size of the square and
** the amout of tetriminos.
*/

typedef	struct	s_params
{
	char	size;
	char	amount;
}				t_params;

/*
** Defining a struct which will be a column object. It has pointers to it's
** neighbours, N stands for name and size has amount of ones in this column.
*/

typedef struct	s_colobj
{
	char			n;
	char			size;
	struct s_colobj	*u;
	struct s_colobj	*l;
	struct s_colobj	*d;
	struct s_colobj	*r;
}				t_colobj;

/*
** Defining a struct which will be a point object. It has pointers to it's
** neighbours, C point to the column object.
*/

typedef struct	s_point
{
	struct s_point	*c;
	struct s_point	*u;
	struct s_point	*l;
	struct s_point	*d;
	struct s_point	*r;
}				t_point;

void		cleansheet(t_colobj arr);
t_colobj	createsheet(t_params params, char *file);
int			ft_sqrt(int num);
int			check_t(char *buf, int count);
t_params	*check(char *str);
#endif
