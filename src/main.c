/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:17:08 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/25 11:53:55 by esnowpea         ###   ########.fr       */
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

void	print_coord(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

int		main(void)
{
	t_filler	*filler;

	if (!(filler = init_filler()))
	{
		write(2, ERR_INPUT, ft_strlen(ERR_INPUT));
		return (0);
	}
	while (parc_input(filler))
	{
		find_place_piece(filler);
		print_coord(filler->out_x, filler->out_y);
		free_all(filler);
		reset_filler(filler);
	}
	free_all(filler);
	while (get_next_line(filler->fd, &filler->gnl) > 0)
		free_null((void**)(&filler->gnl));
	free_null((void**)(&filler));
	return (0);
}
