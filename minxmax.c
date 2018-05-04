/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minxmax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 10:51:22 by cpireyre          #+#    #+#             */
/*   Updated: 2018/04/29 10:56:45 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_y_min(t_tetro tetro)
{
	return (ft_min(ft_min(tetro.oct[0].y, tetro.oct[1].y),
			ft_min(tetro.oct[2].y, tetro.oct[3].y)));
}

size_t	ft_y_max(t_tetro tetro)
{
	return (ft_max(ft_max(tetro.oct[0].y, tetro.oct[1].y),
			ft_max(tetro.oct[2].y, tetro.oct[3].y)));
}

size_t	ft_x_min(t_tetro tetro)
{
	return (ft_min(ft_min(tetro.oct[0].x, tetro.oct[1].x),
			ft_min(tetro.oct[2].x, tetro.oct[3].x)));
}

size_t	ft_x_max(t_tetro tetro)
{
	return (ft_max(ft_max(tetro.oct[0].x, tetro.oct[1].x),
			ft_max(tetro.oct[2].x, tetro.oct[3].x)));
}
