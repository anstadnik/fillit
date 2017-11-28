/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:43:39 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/26 10:57:12 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(void)
{
	t_colobj	*head;
	t_params	p;

	/*
	ft_putendl("");
	ft_putendl("ok_00.uu");
	p.size = 4;
	p.amount = 4;
	head = createsheet(p, "ok_00.uu");
	visualize(head, 0);
	cleansheet(&head);
	*/
	ft_putendl("");
	ft_putendl("ok_01.uu");
	p.size = 4;
	p.amount = 2;
	head = createsheet(p, "ok_01.uu");
	visualize(head, 0);
	cleansheet(&head);
	/*
	ft_putendl("");
	ft_putendl("ok_03.uu");
	p.size = 10;
	p.amount = 25;
	head = createsheet(p, "ok_03.uu");
	//head = createsheet(p, "ok_11_blocks");
	visualize(head, 0);
	cleansheet(&head);
	*/
	return (0);
}
