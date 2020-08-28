/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:31:45 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/25 13:07:18 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_count	count_null(void)
{
	t_count	count;

	count.count_my = 0;
	count.count_star = 0;
	count.count_en = 0;
	count.weight = 0;
	return (count);
}

t_count	pixel_selection_check_part(t_filler *filler, int x, int y)
{
	int		i;
	int		j;
	t_count	count;

	count = count_null();
	i = 0;
	while (i < filler->piece.height && (i + x) < filler->plat.height)
	{
		j = 0;
		while (j < filler->piece.width && (j + y) < filler->plat.width)
		{
			if (filler->piece.map[i][j] == '*' && (x + i >= 0) && (y + j >= 0))
			{
				if (filler->plat.map[i + x][j + y].pixel == filler->en_pixel)
					count.count_en++;
				if (filler->plat.map[i + x][j + y].pixel == filler->my_pixel)
					count.count_my++;
				count.weight += filler->plat.map[i + x][j + y].weight;
				count.count_star++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	pixel_selection_check(t_filler *filler, int x, int y)
{
	t_count	count;

	count = pixel_selection_check_part(filler, x, y);
	if (count.count_my == 1 && count.count_star == filler->piece.star &&
	count.count_en == 0 &&
	(count.weight < filler->out_weight || filler->out_weight == 0))
	{
		filler->out_weight = count.weight;
		filler->out_x = x;
		filler->out_y = y;
	}
}

void	piece_selection_check(t_filler *filler, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->piece.height)
	{
		j = 0;
		while (j < filler->piece.width)
		{
			if (filler->piece.map[i][j] == '*')
				pixel_selection_check(filler, x - i, y - j);
			j++;
		}
		i++;
	}
}

void	find_place_piece(t_filler *filler)
{
	int		i;
	int		j;

	map_change_weight(&filler->plat);
	i = 0;
	while (i < filler->plat.height)
	{
		j = 0;
		while (j < filler->plat.width)
		{
			if (filler->plat.map[i][j].pixel == filler->my_pixel)
				piece_selection_check(filler, i, j);
			j++;
		}
		i++;
	}
}
