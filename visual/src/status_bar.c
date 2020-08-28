/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:43:06 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 16:44:00 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

double		global_ratio(t_plat *plat)
{
	int		i;
	int		j;
	int		counter_b;
	int		counter_r;

	counter_b = 0;
	counter_r = 0;
	i = 0;
	while (i < plat->height)
	{
		j = 0;
		while (j < plat->width)
		{
			if (plat->map[i][j] == 'O' || plat->map[i][j] == 'o')
				counter_b++;
			else if (plat->map[i][j] == 'X' || plat->map[i][j] == 'x')
				counter_r++;
			j++;
		}
		i++;
	}
	return ((double)counter_b / (counter_r + counter_b));
}

void		status_bar(t_img *img, t_plat *plat)
{
	int		r;
	int		i;

	r = (int)round(global_ratio(plat) * WIN_WIDTH);
	i = 0;
	while (i < 20)
	{
		img_line_put(img, set_point(0, i, int_to_color(0xFF)),
		set_point(r, i, int_to_color(0xFF)));
		img_line_put(img, set_point(r, i, int_to_color(0xFF0000)),
		set_point(WIN_WIDTH, i, int_to_color(0xFF0000)));
		i++;
	}
}
