/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:43:49 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 16:47:04 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

char		*find_line(const char *name)
{
	char	*line;
	int		gnl;
	char	*str;

	while ((gnl = get_next_line(0, &line) > 0) &&
			!(str = ft_strstr(line, name)))
	{
		free(line);
		line = NULL;
	}
	if (gnl <= 0)
		return (NULL);
	str += ft_strlen(name);
	str = ft_strdup(str);
	free(line);
	return (str);
}

char		**init_array(int a, int b)
{
	char	**arr;
	int		i;

	if (!(arr = (char**)ft_memalloc(sizeof(char*) * b)))
		return (0);
	i = 0;
	while (i < b)
	{
		if (!(arr[i++] = (char*)ft_memalloc(sizeof(char) * a)))
			return (0);
	}
	return (arr);
}

int			fill_array(t_plat *plat, int i, const char *str)
{
	int		j;

	j = 0;
	while (str[j] && j < plat->width)
	{
		plat->map[i][j] = str[j];
		j++;
	}
	if (j != plat->width)
		return (0);
	return (1);
}

int			fill_map(t_plat *plat)
{
	char	*str;
	int		i;

	if (!(str = find_line("    ")))
		return (0);
	free(str);
	i = 0;
	while (i < plat->height && (str = find_line(" ")))
	{
		if (!fill_array(plat, i, str))
			return (0);
		free(str);
		i++;
	}
	if (i != plat->height)
		return (0);
	return (1);
}

t_plat		*parc_map(void)
{
	t_plat	*plat;
	char	*str;
	char	*tmp;

	if (!(plat = (t_plat*)ft_memalloc(sizeof(t_plat))))
		return (0);
	if (!(str = find_line("Plateau ")))
		return (0);
	tmp = str;
	plat->height = ft_atoi(str);
	if (!(str = ft_strstr(str, " ")))
		return (0);
	plat->width = ft_atoi(str);
	free(tmp);
	if (plat->height <= 0 || plat->width <= 0)
		return (0);
	if (!(plat->map = init_array(plat->width, plat->height)))
		return (0);
	if (!fill_map(plat))
		return (0);
	return (plat);
}
