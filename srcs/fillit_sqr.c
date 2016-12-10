/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_sqr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 08:36:50 by achan             #+#    #+#             */
/*   Updated: 2016/12/09 15:09:03 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_del(t_sqr *sqr)
{
	t_sqr	*to_del;

	if (!sqr)
		return ;
	to_del = (t_sqr *)sqr;
	if (to_del->grid)
	{
		free(to_del->grid);
		to_del->grid = NULL;
	}
	free(to_del);
}

t_sqr	*gen_sqr(int size)
{
	t_sqr	*sqr;

	if (size < 0)
		return (NULL);
	if (!(sqr = (t_sqr *)malloc(sizeof(t_sqr))))
		return (NULL);
	if (!(sqr->grid = (char *)malloc(sizeof(char) * (size * size))))
		sqr->grid = NULL;
	sqr->size = size;
	ft_bzero(sqr->grid, (size * size));
	return (sqr);
}
