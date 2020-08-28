/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:32:33 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 16:51:58 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int					close_press(void *param)
{
	(void)param;
	exit(0);
}

int					key_press(int key, t_filler *filler)
{
	t_plat		*plat;

	if (key == MAIN_PAD_RIGHT)
	{
		if (!(filler->list->next))
		{
			if (!(plat = parc_map()))
				return (0);
			ft_bilstadd_back(&filler->list, ft_bilstnew(plat, sizeof(t_plat)));
		}
		filler->list = filler->list->next;
		print_map(filler);
	}
	if (key == MAIN_PAD_LEFT && filler->list->prev)
	{
		filler->list = filler->list->prev;
		print_map(filler);
	}
	if (key == MAIN_PAD_ESC)
		close_press(filler);
	return (0);
}

void				event_handler(t_filler *filler)
{
	mlx_hook(filler->win->win, 2, 0, key_press, filler);
	mlx_hook(filler->win->win, 17, 0, close_press, filler);
}
