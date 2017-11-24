/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:43:39 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/24 12:01:23 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main()
{
	//ft_putendl("Potato");
	t_colobj	*head;
	t_params	p;
	ft_putendl("");
	ft_putendl("ok_00.uu");
	p.size = 4;
	p.amount = 4;
	head = createsheet(p, "ok_00.uu");
	visualize(head, 1);
	cleansheet(&head);
	ft_putendl("");
	ft_putendl("ok_01.uu");
	p.size = 4;
	p.amount = 2;
	head = createsheet(p, "ok_01.uu");
	visualize(head, 1);
	cleansheet(&head);
	ft_putendl("");
	ft_putendl("ok_03.uu");
	p.size = 6;
	p.amount = 8;
	head = createsheet(p, "ok_03.uu");
	visualize(head, 0);
	cleansheet(&head);
	return (0);
}
