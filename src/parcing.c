/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:22:35 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/25 11:50:49 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		parc_plateau_size(t_filler *filler)
{
	char	*str;
	int		i;

	if (get_next_line(filler->fd, &filler->gnl) <= 0 ||
	!(str = ft_strstr(filler->gnl, "Plateau ")))
		return (0);
	str += ft_strlen("Plateau ");
	filler->plat.height = ft_atoi(str);
	if (!(str = ft_strstr(str, " ")))
		return (0);
	filler->plat.width = ft_atoi(str);
	if (filler->plat.height <= 0 || filler->plat.width <= 0)
		return (0);
	if (!(filler->plat.map = (t_pixel**)ft_memalloc(sizeof(t_pixel*) *
			filler->plat.height)))
		return (0);
	i = 0;
	while (i < filler->plat.height)
	{
		if (!(filler->plat.map[i++] =
			(t_pixel*)ft_memalloc(sizeof(t_pixel) * filler->plat.width)))
			return (0);
	}
	free_null((void**)(&filler->gnl));
	return (1);
}

int		parc_plateau_map(t_filler *filler)
{
	char	*str;
	int		i;

	if (get_next_line(filler->fd, &filler->gnl) <= 0 ||
	!(ft_strstr(filler->gnl, "    ")))
		return (0);
	free_null((void**)(&filler->gnl));
	i = 0;
	while (i < filler->plat.height &&
	get_next_line(filler->fd, &filler->gnl) > 0 &&
	(str = ft_strstr(filler->gnl, " ")))
	{
		str += ft_strlen(" ");
		if (!fill_map(&filler->plat, filler->en_pixel, i, str))
			return (0);
		free_null((void**)(&filler->gnl));
		i++;
	}
	if (i != filler->plat.height)
		return (0);
	return (1);
}

int		parc_piece_size(t_filler *filler)
{
	char	*str;
	int		i;

	if (get_next_line(filler->fd, &filler->gnl) <= 0 ||
	!(str = ft_strstr(filler->gnl, "Piece ")))
		return (0);
	str += ft_strlen("Piece ");
	filler->piece.height = ft_atoi(str);
	if (!(str = ft_strstr(str, " ")))
		return (0);
	filler->piece.width = ft_atoi(str);
	if (filler->piece.height <= 0 || filler->piece.width <= 0)
		return (0);
	if (!(filler->piece.map =
			(char**)ft_memalloc(sizeof(char*) * filler->piece.height)))
		return (0);
	i = 0;
	while (i < filler->piece.height)
	{
		if (!(filler->piece.map[i++] =
				(char*)ft_memalloc(sizeof(char) * filler->piece.width)))
			return (0);
	}
	free_null((void**)(&filler->gnl));
	return (1);
}

int		parc_piece_map(t_filler *filler)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (i < filler->piece.height &&
	get_next_line(filler->fd, &filler->gnl) > 0)
	{
		str = filler->gnl;
		j = 0;
		while (str[j] && j < filler->piece.width)
		{
			filler->piece.map[i][j] = str[j];
			filler->piece.star += str[j] == '*' ? 1 : 0;
			j++;
		}
		if (j != filler->piece.width)
			return (0);
		free_null((void**)(&filler->gnl));
		i++;
	}
	free_null((void**)(&filler->gnl));
	if (i != filler->piece.height)
		return (0);
	return (1);
}

int		parc_input(t_filler *filler)
{
	if (!parc_plateau_size(filler) || !parc_plateau_map(filler) ||
	!parc_piece_size(filler) || !parc_piece_map(filler))
		return (0);
	return (1);
}
