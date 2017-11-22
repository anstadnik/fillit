/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:43:39 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/22 20:14:19 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main()
{
	//ft_putendl("Potato");
	t_colobj	*head;
	t_params	p;
	p.size = 4;
	p.amount = 2;
	head = createsheet(p, "ok_01");
	visualize(head);
	cleansheet(&head);
	return (0);
}
