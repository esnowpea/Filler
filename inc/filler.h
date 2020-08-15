/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:18:08 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/15 19:27:15 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define MY_NAME		"esnowpea.filler"
# define ERR_INPUT		"ERROR: Bad input\n"

typedef struct			s_pixel
{
	char				pixel;
	int					weight;
}						t_pixel;

typedef struct			s_plat
{
	int					width;
	int					height;
	t_pixel				**map;
}						t_plat;

typedef struct			s_piece
{
	int					width;
	int					height;
	int					star;
	char				**map;
}						t_piece;

typedef struct			s_filler
{
	char				my_pixel;
	char				en_pixel;
	int					out_x;
	int					out_y;
	int					out_weight;
	t_plat				plat;
	t_piece				piece;
	char				*gnl;
	int					fd;
}						t_filler;

t_filler				*init_filler(void);
int						parc_input(t_filler *filler);
int						parc_player(t_filler *filler);
void					free_null(void **var);
void					free_all(t_filler *filler);
void					make_null_pointer(void **array, int n);
void					*terminate(char *str, t_filler *filler);
void					find_place_piece(t_filler *filler);
void					reset_filler(t_filler *filler);

void					print_map(t_filler *filler);

#endif
