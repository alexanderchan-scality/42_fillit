/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 08:09:52 by achan             #+#    #+#             */
/*   Updated: 2016/12/09 20:09:23 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_print_s(t_sqr *sqr, int size)
{
	int		cnt;
	int		i_cnt;
	int		side;
	int		area;
	char	c;

	cnt = 0;
	i_cnt = 0;
	side = sqr->size;
	area = size * size;
	while (cnt < area && i_cnt++ < side * side)
	{
		c = sqr->grid[cnt];
		if (c >= 'A' && c <= 'Z')
			write(1, &c, 1);
		else
			write(1, ".", 1);
		if (cnt % size == side - 1)
		{
			cnt = ((cnt / size) + 1) * size;
			write(1, "\n", 1);
		}
		else
			++cnt;
	}
}

void	fillit_print_t(t_tetris *pieces, int p_cnt)
{
	int			i;
	int			b_cnt;
	t_tetris	to_print;

	i = 0;
	while (i < p_cnt)
	{
		b_cnt = 0;
		to_print = (t_tetris)*(g_shp[pieces[i]]);
		while (b_cnt < 16)
		{
			if (to_print & ((0x8000) >> b_cnt))
				write(1, "#", 1);
			else
				write(1, ".", 1);
			if (b_cnt % 4 == 3)
				write(1, "\n", 1);
			++b_cnt;
		}
		if (i != p_cnt - 1)
			write(1, "\n", 1);
		++i;
	}
}
