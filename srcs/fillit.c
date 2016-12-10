/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 07:46:53 by achan             #+#    #+#             */
/*   Updated: 2016/12/10 02:37:47 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_sqrt(int n)
{
	int	i;

	i = 0;
	while (i < 65536)
	{
		if (i * i > n)
			return (i);
		++i;
	}
	return (0);
}

int		perf_sqr(int size)
{
	int tmp;

	tmp = size;
	if (tmp == 4 || tmp == 16 || tmp == 36 || tmp == 64 || tmp == 100)
		return (1);
	return (0);
}

int		err_check(t_sqr *ret, int size)
{
	int		r_size;
	int		ind;
	int		cnt;
	int		flag;
	char	*grid;

	grid = ret->grid;
	r_size = ret->size;
	ind = r_size - 1;
	flag = 1;
	while (flag && ind >= 0)
	{
		cnt = 0;
		while (flag && cnt < r_size)
		{
			if (grid[cnt + ind * size])
				flag = 0;
			++cnt;
		}
		if (flag)
			--ind;
	}
	return (ind + 1);
}

void	fillit_solve(t_tetris *p, int p_cnt)
{
	t_sqr	*sqr;
	t_sqr	*ret;
	int		size;

	size = min_sqrt(p_cnt * 4) + 1;
	if (!(sqr = gen_sqr(size)))
		return ;
	if (!(ret = gen_sqr(size)))
		return ;
	ret->size = 0;
	fillit_algo(sqr, ret, p, 0);
	fillit_print_s(ret, size);
	fillit_del(sqr);
	fillit_del(ret);
}

void	fillit(char *file)
{
	int			fd;
	int			p_cnt;
	t_tetris	pieces[27];

	if ((fd = open(file, O_RDONLY)) < 0)
		error_exit(2);
	p_cnt = 0;
	fillit_read(pieces, &p_cnt, fd);
	pieces[p_cnt] = 0;
	if ((close(fd) < 0))
		error_exit(2);
	fillit_solve(pieces, p_cnt);
}
