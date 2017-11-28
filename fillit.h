/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:23:37 by lburlach          #+#    #+#             */
/*   Updated: 2017/11/28 12:14:14 by astadnik         ###   ########.fr       */
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
	void			*u;
	void			*l;
	void			*d;
	void			*r;
}				t_colobj;

/*
** Defining a struct which will be a point object. It has pointers to it's
** neighbours, C point to the column object.
*/

typedef struct	s_point
{
	void			*c;
	void			*u;
	void			*l;
	void			*d;
	void			*r;
}				t_point;

/*
** Defining a usual list
*/

typedef struct	s_filist
{
	t_point			*data;
	struct s_filist	*next;
}				t_filist;

void			cleansheet(t_colobj **head);
t_colobj		*createsheet(t_params params, char *path);
char			getindex(char n, char i);
char			setindex(char n1, char n2);
char			fillsheet(t_colobj *head, int fd, char size);
void			visualize(t_colobj *head, char f1, char f2, t_colobj *last);
char			solve(t_colobj *head, char size);
void			print(t_filist *rez, char size);
char			del(t_point *p, t_filist **rez);
void			restore(t_filist **rez);
int				ft_sqrt(int num);
int				check_t(char *buf, int count);
#endif
