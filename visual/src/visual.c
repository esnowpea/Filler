/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:43:27 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 16:46:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

char		*name_fix(char *name)
{
	char		*str;
	char		*tmp;

	if (!name)
		return (0);
	if (!(str = ft_strstr(name, ".filler")))
		return (0);
	*str = '\0';
	str--;
	while (*(str - 1) != '/')
		str--;
	tmp = ft_strdup(str);
	free(name);
	return (tmp);
}

t_filler	*init_filler(void)
{
	t_filler	*filler;
	t_plat		*plat;

	if (!(filler = (t_filler*)ft_memalloc(sizeof(t_filler))))
		return (0);
	filler->win = init_visual("vs");
	if (!(filler->name_player1 = name_fix(find_line("$$$ exec p1 : ["))))
		return (0);
	if (!(filler->name_player2 = name_fix(find_line("$$$ exec p2 : ["))))
		return (0);
	if (!(plat = parc_map()))
		return (0);
	if (!(filler->list = ft_bilstnew(plat, sizeof(t_plat))))
		return (0);
	return (filler);
}

int			main(void)
{
	t_filler	*filler;

	if (!(filler = init_filler()))
		terminate(ERR_BAD_INPUT);
	img_backgraund_put(filler->win->img, filler->list->content);
	print_map(filler);
	event_handler(filler);
	mlx_loop(filler->win->mlx);
	return (0);
}
