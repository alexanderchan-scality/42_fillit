/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_def.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 07:46:58 by achan             #+#    #+#             */
/*   Updated: 2016/12/09 20:06:44 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris const	g_sq[10] =
{0xCC00, 0x6600, 0x3300, 0x0CC0, 0x0660, 0x0330, 0x00CC, 0x0066, 0x0033, 0};

t_tetris const	g_ui[5] =
{0x8888, 0x4444, 0x2222, 0x1111, 0};

t_tetris const	g_di[5] =
{0xF000, 0x0F00, 0x00F0, 0x000F, 0};

t_tetris const	g_uz[7] =
{0x8C40, 0x4620, 0x2310, 0x08C4, 0x0462, 0x0231, 0};
t_tetris const	g_dz[7] =
{0x4C80, 0x2640, 0x1320, 0x04C8, 0x0264, 0x0132, 0};
t_tetris const	g_lz[7] =
{0xC600, 0x6300, 0x0C60, 0x0630, 0x00C6, 0x0063, 0};
t_tetris const	g_rz[7] =
{0x6C00, 0x3600, 0x06C0, 0x0360, 0x006C, 0x0036, 0};

t_tetris const	g_ut[7] =
{0x4E00, 0x2700, 0x04E0, 0x0270, 0x004E, 0x0027, 0};
t_tetris const	g_dt[7] =
{0xE400, 0x7200, 0x0E40, 0x0720, 0x00E4, 0x0072, 0};
t_tetris const	g_lt[7] =
{0x4C40, 0x2620, 0x1310, 0x04C4, 0x0262, 0x0131, 0};
t_tetris const	g_rt[7] =
{0x8C80, 0x4640, 0x2320, 0x08C8, 0x0464, 0x0232, 0};

t_tetris const	g_ul[7] =
{0xC440, 0x6220, 0x3110, 0x0C44, 0x0622, 0x0311, 0};
t_tetris const	g_dl[7] =
{0x88C0, 0x4460, 0x2230, 0x088C, 0x0446, 0x0223, 0};
t_tetris const	g_ll[7] =
{0xE800, 0x7400, 0x0E80, 0x0740, 0x00E8, 0x0074, 0};
t_tetris const	g_rl[7] =
{0x2E00, 0x1700, 0x02E0, 0x0170, 0x002E, 0x0017, 0};

t_tetris const	g_uj[7] =
{0xC880, 0x6440, 0x3220, 0x0C88, 0x0644, 0x0322, 0};
t_tetris const	g_dj[7] =
{0x44C0, 0x2260, 0x1130, 0x044C, 0x0226, 0x0113, 0};
t_tetris const	g_lj[7] =
{0x8E00, 0x4700, 0x08E0, 0x0470, 0x008E, 0x0047, 0};
t_tetris const	g_rj[7] =
{0xE200, 0x7100, 0x0E20, 0x0710, 0x00E2, 0x0071, 0};

t_dms const		g_dms[20] =
{
	{0, 0}, {2, 2}, {1, 4}, {4, 1},
	{2, 3}, {2, 3}, {3, 2}, {3, 2},
	{3, 2}, {3, 2}, {2, 3}, {2, 3},
	{2, 3}, {2, 3}, {3, 2}, {3, 2},
	{2, 3}, {2, 3}, {3, 2}, {3, 2}
};

t_tetris const	*g_shp[20] =
{
	NULL, g_sq, g_ui, g_di,
	g_uz, g_dz, g_lz, g_rz,
	g_ut, g_dt, g_lt, g_rt,
	g_ul, g_dl, g_ll, g_rl,
	g_uj, g_dj, g_lj, g_rj
};

char const		*g_err_msg[3] =
{
	"Nothing wrong\n",
	"usage:\t./fillit\tsource_file\n",
	"error\n"
};
