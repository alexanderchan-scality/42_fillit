/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:47:00 by achan             #+#    #+#             */
/*   Updated: 2016/12/09 23:28:47 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_unset(t_sqr *sqr, t_tetris *p, int p_cnt, int pos)
{
	char	*grid;
	int		size;
	int		ind;

	grid = sqr->grid;
	size = sqr->size;
	ind = 0;
	while (ind < 16)
	{
		if (((pos % size) + (ind % 4) < size &&
			(pos / size) + (ind / 4) < size) &&
			(*p & (0x8000) >> ind))
		{
			if (p_cnt >= 0)
				grid[pos + (ind % 4) + (ind / 4) * size] = 'A' + p_cnt;
			else
				grid[pos + (ind % 4) + (ind / 4) * size] = 0;
		}
		++ind;
	}
}

static int		settable(t_sqr *sqr, t_tetris *p, int pos)
{
	int			size;
	int			ind;
	t_tetris	q;

	size = sqr->size;
	ind = 0;
	q = 0;
	while (ind < 16)
	{
		if ((pos % size) + (ind % 4) >= size ||
			(pos / size) + (ind / 4) >= size)
			q |= (0x8000 >> ind);
		else
		{
			if ((sqr->grid)[pos + (ind % 4) + (ind / 4) * size])
				q |= (0x8000 >> ind);
		}
		++ind;
	}
	return (!(q & *p));
}

static int		reducible(t_sqr *sqr)
{
	int		size;
	int		ind;
	int		cnt;
	int		flag;
	char	*grid;

	grid = sqr->grid;
	size = sqr->size;
	ind = size - 1;
	flag = 1;
	while (flag && ind >= 0)
	{
		cnt = 0;
		while (flag && cnt < size)
		{
			if (grid[ind + cnt * size] ||
				grid[cnt + ind * size])
				flag = 0;
			++cnt;
		}
		if (flag)
			--ind;
	}
	return (ind + 1);
}

static t_sqr	*sqr_check(t_sqr *sqr, t_sqr *ret)
{
	int size;

	size = reducible(sqr);
	if (size < ret->size)
	{
		ft_memcpy(ret->grid, sqr->grid, (sqr->size * sqr->size));
		ret->size = size;
		return (ret);
	}
	return (NULL);
}

t_sqr		*fillit_algo(t_sqr *sqr, t_sqr *ret, t_tetris *p, int p_cnt)
{
	int		pos;
	t_sqr	*tmp;

	if (!*p)
		return sqr_check(sqr, ret);
	pos = 0;
	while (pos < (sqr->size * sqr->size))
	{
		if (settable(sqr, (t_tetris *)g_shp[*p], pos))
		{
			set_unset(sqr, (t_tetris *)g_shp[*p], p_cnt, pos);
			/*system("clear");*/
			/*fillit_print_s(sqr, sqr->size);*/
			tmp = fillit_algo(sqr, ret, p + 1, p_cnt + 1);
			if (tmp && tmp->size < sqr->size)
				return (ret);
			set_unset(sqr, (t_tetris *)g_shp[*p], -1, pos);
		}
		++pos;
	}
	return (NULL);
}

