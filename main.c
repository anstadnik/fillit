/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:43:39 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/30 19:57:19 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_colobj	*head;
	t_params	*p;
	char		f;

	if (ac != 2 || !(p = check(av[1])))
	{
		ft_putendl("error");
		return (0);
	}
	head = createsheet(*p, av[1]);
	f = solve(head, p->size);
	while (!f)
	{
		p->size++;
		cleansheet(&head);
		head = createsheet(*p, av[1]);
		f = solve(head, p->size);
	}
	free(p);
	cleansheet(&head);
	return (0);
}
