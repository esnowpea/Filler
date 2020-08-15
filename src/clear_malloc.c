/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:33:43 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/15 17:55:34 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_null(void **var)
{
	if (var && *var)
	{
		free(*var);
		*var = NULL;
	}
}

void	free_plat(t_plat *plat)
{
	int		i;

	if (plat->map)
	{
		i = 0;
		while (i < plat->height)
		{
			if (plat->map[i])
				free_null((void **)(&plat->map[i]));
			i++;
		}
		free_null((void**)(&plat->map));
	}
}

void	free_piece(t_piece *plat)
{
	int		i;

	if (plat->map)
	{
		i = 0;
		while (i < plat->height)
		{
			if (plat->map[i])
				free_null((void **)(&plat->map[i]));
			i++;
		}
		free_null((void**)(&plat->map));
	}
}

void	free_all(t_filler *filler)
{
	if (filler)
	{
		free_plat(&filler->plat);
		free_piece(&filler->piece);
		free_null((void**)(&filler->gnl));
	}
}

void	*terminate(char *str, t_filler *filler)
{
	free_all(filler);
	while (get_next_line(filler->fd, &filler->gnl) > 0)
		free_null((void**)(&filler->gnl));
	free_null((void**)(&filler));
	ft_printf_fd(2, "%s\n", str);
	return (NULL);
}
