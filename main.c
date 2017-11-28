/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:43:39 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/28 16:30:47 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_colobj	*head;
	t_params	p;
	char		f;

	if (ac != 2 || !check(av[1]))
	{
		ft_putendl("error");
		return (0);
	}
	p = *check(av[1]);
	head = createsheet(p, av[1]);
//	visualize(head, 0, 1, NULL);
	f = solve(head, p.size);
	while (!f)
	{
		p.size++;
		cleansheet(&head);
		head = createsheet(p, av[1]);
//		visualize(head, 0, 1, NULL);
		f = solve(head, p.size);
	}
	cleansheet(&head);
	return (0);
}
