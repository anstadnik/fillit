/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleansheet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:59:32 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/25 20:17:14 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Frees memory in sheet
*/

#include "fillit.h"

void		cleansheet(t_colobj **head)
{
	void	*curc;
	void	*curp;
	void	*temp;

	if (!head || !*head)
		return ;
	curc = (*head)->r;
	while (curc != *head)
	{
		curp = ((t_colobj*)curc)->d;
		while (curp != curc)
		{
			temp = curp;
			curp = ((t_point *)curp)->d;
			free(temp);
		}
		temp = curc;
		curc = ((t_colobj *)curc)->r;
		free(temp);
	}
	free(*head);
}
