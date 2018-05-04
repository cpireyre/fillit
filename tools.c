/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 10:58:59 by cpireyre          #+#    #+#             */
/*   Updated: 2018/04/29 10:59:00 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_exit_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

t_point	ft_build_point(int a, int b)
{
	t_point	point;

	point.x = a;
	point.y = b;
	return (point);
}
