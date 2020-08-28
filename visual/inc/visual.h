/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:38:51 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 16:46:37 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft.h"
# include "libvisual.h"

# define ERR_BAD_INPUT	"ERROR: Bad input"

typedef struct			s_plat
{
	int					width;
	int					height;
	char				**map;
}						t_plat;

typedef struct			s_filler
{
	char				*name_player1;
	char				*name_player2;
	t_bilist			*list;
	t_win				*win;
}						t_filler;

char					*find_line(const char *name);
t_plat					*parc_map();
void					print_map(t_filler *filler);
void					event_handler(t_filler *filler);
void					status_bar(t_img *img, t_plat *plat);
void					img_backgraund_put(t_img *img, t_plat *plat);

#endif
