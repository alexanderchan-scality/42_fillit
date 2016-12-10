/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 07:47:25 by achan             #+#    #+#             */
/*   Updated: 2016/12/07 08:40:02 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	read_err(int fd)
{
	close(fd);
	ft_putstr(g_err_msg[2]);
	exit(0);
}

static void	general_err(int err)
{
	ft_putstr(g_err_msg[err]);
	exit(0);
}

void		error_exit(int err)
{
	if (err <= 2)
		general_err(err);
	read_err(err);
}
