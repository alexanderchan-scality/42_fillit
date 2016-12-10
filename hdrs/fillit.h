/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 23:19:25 by achan             #+#    #+#             */
/*   Updated: 2016/12/10 02:37:11 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>

typedef unsigned short	t_tetris;

typedef struct			s_dms
{
	int					w;
	int					h;
}						t_dms;

typedef struct			s_sqr
{
	char				*grid;
	int					size;
}						t_sqr;

extern t_tetris const	g_sq[10];
extern t_tetris const	g_ui[5];
extern t_tetris const	g_di[5];
extern t_tetris const	g_rz[7];
extern t_tetris const	g_uz[7];
extern t_tetris const	g_lz[7];
extern t_tetris const	g_dz[7];
extern t_tetris const	g_ut[7];
extern t_tetris const	g_dt[7];
extern t_tetris const	g_rt[7];
extern t_tetris const	g_lt[7];
extern t_tetris const	g_ul[7];
extern t_tetris const	g_dl[7];
extern t_tetris const	g_rl[7];
extern t_tetris const	g_ll[7];
extern t_tetris const	g_uj[7];
extern t_tetris const	g_dj[7];
extern t_tetris const	g_rj[7];
extern t_tetris const	g_lj[7];
extern t_dms const		g_dms[20];
extern t_tetris const	*g_shp[20];
extern char const		*g_err_msg[3];

void					fillit(char *file);
void					fillit_solve(t_tetris *pieces, int p_cnt);

int						min_sqrt(int n);
int						perf_sqr(int n);
int						err_check(t_sqr *ret, int size);

void					fillit_read(t_tetris *pieces, int *p_cnt, int fd);
void					fillit_print_t(t_tetris *pieces, int p_cnt);
void					fillit_print_s(t_sqr *sqr, int size);
t_sqr					*fillit_algo(t_sqr *sqr, t_sqr *ret,
										t_tetris *p, int p_cnt);
t_sqr					*gen_sqr(int size);
void					fillit_del(t_sqr *sqr);

void					error_exit(int err);
#endif
