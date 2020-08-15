/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:37:22 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/15 19:23:18 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			parc_player(t_filler *filler)
{
	char	*tmp;

	if (get_next_line(filler->fd, &filler->gnl) <= 0 ||
		!ft_strstr(filler->gnl, MY_NAME))
		return (0);
	tmp = ft_strstr(filler->gnl, "$$$ exec ");
	if (!tmp)
		return (0);
	tmp += ft_strlen("$$$ exec ");
	if (ft_strnequ(tmp, "p1", 2))
	{
		filler->my_pixel = 'O';
		filler->en_pixel = 'X';
		free_null((void**)(&filler->gnl));
		return (1);
	}
	else if (ft_strnequ(tmp, "p2", 2))
	{
		filler->my_pixel = 'X';
		filler->en_pixel = 'O';
		free_null((void**)(&filler->gnl));
		return (1);
	}
	return (0);
}

t_filler	*init_filler(void)
{
	t_filler	*filler;

	if (!(filler = (t_filler*)malloc(sizeof(t_filler))))
		return (0);
	reset_filler(filler);
	filler->fd = 0;
	if (!(parc_player(filler)))
	{
		free_null((void**)(&filler->gnl));
		free_null((void**)(&filler));
		return (0);
	}
	return (filler);
}

void		make_null_pointer(void **array, int n)
{
	int		i;

	i = 0;
	while (i < n)
		array[i++] = NULL;
}
