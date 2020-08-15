/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:17:08 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/15 18:49:36 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reset_filler(t_filler *filler)
{
	filler->gnl = NULL;
	filler->plat.map = NULL;
	filler->piece.map = NULL;
	filler->piece.star = 0;
	filler->out_weight = 0;
	filler->out_x = 0;
	filler->out_y = 0;
}

int		main(void)
{
	t_filler	*filler;

	if (!(filler = init_filler()))
		return ((int)terminate(ERR_INPUT, filler));
	while (parc_input(filler))
	{
		find_place_piece(filler);
		ft_putnbr(filler->out_x);
		ft_putchar(' ');
		ft_putnbr(filler->out_y);
		ft_putchar('\n');
		free_all(filler);
		reset_filler(filler);
	}
	while (get_next_line(filler->fd, &filler->gnl) > 0)
		free_null((void**)(&filler->gnl));
	free_null((void**)(&filler));
	return (0);
}
