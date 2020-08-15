/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:31:45 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/15 19:03:36 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	one_pixel_change_weight(t_plat *plat, int i, int j, int weight)
{
	if (i > 0 && plat->map[i - 1][j].weight == -1)
		plat->map[i - 1][j].weight = weight + 1;
	if (i < (plat->height - 1) && plat->map[i + 1][j].weight == -1)
		plat->map[i + 1][j].weight = weight + 1;
	if (j > 0 && plat->map[i][j - 1].weight == -1)
		plat->map[i][j - 1].weight = weight + 1;
	if (j < (plat->width - 1) && plat->map[i][j + 1].weight == -1)
		plat->map[i][j + 1].weight = weight + 1;
}

int		pixel_change_weight(t_plat *plat, char pixel, int weight)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (i < plat->height)
	{
		j = 0;
		while (j < plat->width)
		{
			if (plat->map[i][j].pixel == pixel &&
			plat->map[i][j].weight == weight)
			{
				one_pixel_change_weight(plat, i, j, weight);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	map_change_weight(t_plat *plat, char en_pixel)
{
	int		i;

	pixel_change_weight(plat, en_pixel, 0);
	i = 1;
	while (pixel_change_weight(plat, '.', i))
		i++;
}

void	pixel_selection_check(t_filler *filler, int x, int y)
{
	int		i;
	int		j;
	int		count_my;
	int		weight;
	int		count_star;

	count_my = 0;
	weight = 0;
	count_star = 0;
	i = 0;
	while (i < filler->piece.height && (i + x) < filler->plat.height)
	{
		j = 0;
		while (j < filler->piece.width && (j + y) < filler->plat.width)
		{
			if (filler->piece.map[i][j] == '*' && (x + i > 0) && (y + j > 0) &&
			filler->plat.map[i + x][j + y].pixel == filler->my_pixel)
				count_my++;
			if (filler->piece.map[i][j] == '*' && (x + i > 0) && (y + j > 0) &&
				filler->plat.map[i + x][j + y].pixel == filler->en_pixel)
				return ;
			if (filler->piece.map[i][j] == '*' && (x + i > 0) && (y + j > 0))
			{
				weight += filler->plat.map[i + x][j + y].weight;
				count_star++;
			}
			j++;
		}
		i++;
	}
	if (count_my == 1 && count_star == filler->piece.star &&
	(weight < filler->out_weight || filler->out_weight == 0))
	{
		filler->out_weight = weight;
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

	map_change_weight(&filler->plat, filler->en_pixel);
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
