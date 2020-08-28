/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_change_weight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:10:35 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/25 13:10:35 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fill_map(t_plat *plat, char en_pixel, int i, const char *str)
{
	int		j;

	j = 0;
	while (str[j] && j < plat->width)
	{
		plat->map[i][j].pixel = str[j];
		plat->map[i][j].weight = str[j] == en_pixel ? 0 : -1;
		j++;
	}
	if (j != plat->width)
		return (0);
	return (1);
}

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

int		pixel_change_weight(t_plat *plat, int weight)
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
			if (plat->map[i][j].weight == weight)
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

void	map_change_weight(t_plat *plat)
{
	int		i;

	i = 0;
	while (pixel_change_weight(plat, i))
		i++;
}
