/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:43:39 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/26 13:52:53 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(void)
{
	t_colobj	*head;
	t_params	p;
	char		*sol;
	char		f;

	sol = NULL;
	ft_putendl("");
	ft_putendl("ok_03.uu");
	p.size = 10;
	p.amount = 25;
	head = createsheet(p, "ok_03.uu");
	//visualize(head, 0);
	f = solve(&sol, head, p.size);
	while (!f)
		f = solve(&sol, head, ++(p.size));
	if (f == 1)
	{
		print(sol);
		free(sol);
	}
	cleansheet(&head);
	return (0);
}
