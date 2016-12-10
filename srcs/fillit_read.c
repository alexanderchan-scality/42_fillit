/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 07:47:37 by achan             #+#    #+#             */
/*   Updated: 2016/12/10 02:47:18 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetris	fillit_valid(t_tetris curr_p)
{
	unsigned int	i;
	unsigned int	j;
	t_tetris		*valid_t;
	t_tetris		valid_p;

	i = 0;
	if (!curr_p)
		return (0);
	while ((valid_t = (t_tetris *)g_shp[(++i % 20)]))
	{
		j = 0;
		while ((valid_p = (t_tetris)valid_t[j++]))
		{
			if (curr_p == valid_p)
				return (i);
		}
	}
	return (0);
}

static t_tetris	fillit_gen(char *b, int size)
{
	unsigned short	len;
	unsigned short	i;
	t_tetris		ret;

	len = 0;
	i = 0;
	ret = 0;
	if (size < 20)
		return (0);
	while (*b)
	{
		if ((*b != '\n' && *b != '#' && *b != '.') ||
			(*b == '\n' && len % 5 != 4 && size == 20))
			return (0);
		if (*b == '#' || *b == '.')
		{
			if (len % 5 == 4)
				return (0);
			ret |= (*b == '#') ? ((0x8000) >> (i)) : 0;
			++i;
		}
		++len;
		b++;
	}
	return (ret);
}

void			fillit_read(t_tetris *pieces, int *p_cnt, int fd)
{
	int				ret;
	int				l_ret;
	char			b[22];
	t_tetris		curr_p;

	l_ret = 0;
	while ((ret = read(fd, b, 21)))
	{
		if (ret < 0)
			error_exit(fd);
		b[ret] = 0;
		if (!(curr_p = fillit_gen(b, ret)))
			error_exit(fd);
		if ((pieces[*p_cnt] = fillit_valid(curr_p)))
			++(*p_cnt);
		else
			error_exit(fd);
		if (*p_cnt > 26)
			error_exit(fd);
		l_ret = ret;
	}
	if (l_ret == 21 || l_ret == 0)
		error_exit(fd);
}
