/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:43:39 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/28 15:39:39 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(void)
{
	t_colobj	*head;
	t_params	p;
	char		f;

//	ft_putendl("");
//	ft_putendl("ok_03.uu");
	p.size = 7;
	p.amount = 10;
	head = createsheet(p, "ok_10");
//	visualize(head, 0, 1, NULL);
	f = solve(head, p.size);
	while (!f)
	{
		p.size++;
		ft_putnbr(p.size);
		ft_putendl("");
		cleansheet(&head);
		head = createsheet(p, "ok_10");
//		visualize(head, 0, 1, NULL);
		f = solve(head, p.size);
	}
	cleansheet(&head);
	return (0);
}
