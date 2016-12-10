/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 07:46:53 by achan             #+#    #+#             */
/*   Updated: 2016/12/09 23:35:05 by achan            ###   ########.fr       */
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
		{
			/*if (n == 4 || n == 16 || n == 36 || n == 64 || n == 100)*/
				/*return (i);*/
			/*else*/
				return (i);
		}
		++i;
	}
	return (0);
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
	ret->size = size + 1;
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
