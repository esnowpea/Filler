/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:44:50 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 16:50:54 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	img_dot_put(t_img *img, int n, t_point p)
{
	t_color color;

	color = img_get_color(img, p.x, p.y);
	if (color.alpha != p.color.alpha || color.red != p.color.red ||
		color.green != p.color.green || color.blue != p.color.blue)
	{
		n -= n / 5;
		img_rectangle_put(img, set_point(p.x - n / 2, p.y - n / 2, p.color),
					set_point(p.x + n / 2, p.y + n / 2, p.color));
	}
}

void	img_backgraund_put(t_img *img, t_plat *plat)
{
	int			i;
	int			j;
	int			n;
	t_point		p;

	img_rectangle_put(img, set_point(0, 0, int_to_color(0x800000)),
	set_point(WIN_WIDTH, WIN_HEIGHT, int_to_color(0x000080)));
	n = WIN_WIDTH / (plat->width + 2) > (WIN_HEIGHT - 20) / (plat->height + 2) ?
		(WIN_HEIGHT - 20) / (plat->height + 2) : WIN_WIDTH / (plat->width + 2);
	p = set_point(WIN_WIDTH / 2 - plat->width / 2 * n +
			(plat->width % 2 == 0 ? n / 2 : 0),
			WIN_HEIGHT / 2 - plat->height / 2 * n +
			(plat->height % 2 == 0 ? n / 2 : 0), int_to_color(0x0));
	i = 0;
	while (i < plat->height)
	{
		j = 0;
		while (j < plat->width)
		{
			img_dot_put(img, n, set_point(p.x + j * n, p.y + i * n, p.color));
			j++;
		}
		i++;
	}
	status_bar(img, plat);
}

t_color	check_pixel(char pixel)
{
	if (pixel == 'O')
		return (int_to_color(0x51a9fb));
	else if (pixel == 'X')
		return (int_to_color(0xf82a2a));
	else if (pixel == 'o')
		return (int_to_color(0x66fafa));
	else if (pixel == 'x')
		return (int_to_color(0xfdc9c9));
	else
		return (int_to_color(0x0));
}

void	img_print_map(t_img *img, t_plat *plat)
{
	int			i;
	int			j;
	int			n;
	t_point		p;

	n = WIN_WIDTH / (plat->width + 2) > (WIN_HEIGHT - 20) / (plat->height + 2) ?
		(WIN_HEIGHT - 20) / (plat->height + 2) : WIN_WIDTH / (plat->width + 2);
	p = set_point(WIN_WIDTH / 2 - plat->width / 2 * n +
			(plat->width % 2 == 0 ? n / 2 : 0),
			WIN_HEIGHT / 2 - plat->height / 2 * n +
			(plat->height % 2 == 0 ? n / 2 : 0), int_to_color(0x0));
	i = 0;
	while (i < plat->height)
	{
		j = 0;
		while (j < plat->width)
		{
			img_dot_put(img, n, set_point(p.x + j * n, p.y + i * n,
					check_pixel(plat->map[i][j])));
			j++;
		}
		i++;
	}
	status_bar(img, plat);
}

void	print_map(t_filler *filler)
{
	img_print_map(filler->win->img, filler->list->content);
	print_img_to_win(filler->win);
	mlx_string_put(filler->win->mlx, filler->win->win, 0, 0, 0xffffff,
				filler->name_player1);
	mlx_string_put(filler->win->mlx, filler->win->win, WIN_WIDTH - 10 *
	ft_strlen(filler->name_player2), 0, 0xfffff,
				filler->name_player2);
}
