/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:43:39 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/28 09:41:18 by astadnik         ###   ########.fr       */
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
	ft_putendl("ok_01.uu");
	p.size = 4;
	p.amount = 2;
	ft_putnbr(p.size);
	head = createsheet(p, "ok_01.uu");
	visualize(head, 0);
	f = solve(&sol, head, p.size);
	while (!f)
	{
		p.size++;
		ft_putnbr(p.size);
		sol = NULL;
		visualize(head, 0);
		cleansheet(&head);
		head = createsheet(p, "ok_01.uu");
		visualize(head, 0);
		f = solve(&sol, head, p.size);
	}
	if (f == 1)
	{
		print(sol);
		free(sol);
	}
	cleansheet(&head);
	return (0);
}
