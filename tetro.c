/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:37:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/01 15:44:51 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_normalize(t_tetro *tetro)
{
	int		minx;
	int		miny;
	size_t	point;

	minx = ft_x_min(*tetro);
	miny = ft_y_min(*tetro);
	point = 0;
	while (point < 4)
	{
		tetro->oct[point].x -= minx;
		tetro->oct[point].y -= miny;
		point++;
	}
}

t_tetro		ft_create_tetro(const char *valid_block, char letter)
{
	t_tetro	tetro;
	size_t	num;
	int		i;

	num = 0;
	i = 0;
	if (!ft_check_block(valid_block))
		ft_exit_error();
	tetro.letter = letter;
	while (valid_block[i] && i < 20 && num < 4)
	{
		if (valid_block[i] == '#' && num < 4)
			tetro.oct[num++] = ft_build_point(i % 5, i / 5);
		i++;
	}
	ft_normalize(&tetro);
	return (tetro);
}

int			ft_shift(t_tetro *tetro, size_t size)
{
	size_t	maxx;
	size_t	maxy;
	size_t	minx;
	size_t	point;

	point = 0;
	maxy = ft_y_max(*tetro);
	minx = ft_x_min(*tetro);
	if ((maxx = ft_x_max(*tetro)) + 1 < size)
	{
		while (point < 4)
			tetro->oct[point++].x++;
	}
	else
	{
		while (point < 4)
		{
			tetro->oct[point].x -= minx;
			tetro->oct[point++].y++;
		}
	}
	return (1);
}

int			ft_place_tetro(int **grid, t_tetro tetro, size_t size)
{
	size_t	point;

	point = 0;
	if (ft_x_max(tetro) >= size || ft_y_max(tetro) >= size)
		return (-1);
	while (point < 4)
	{
		if (grid[tetro.oct[point].y][tetro.oct[point].x] != '.')
			return (0);
		point++;
	}
	point = 0;
	while (point < 4)
	{
		grid[tetro.oct[point].y][tetro.oct[point].x] = (int)tetro.letter;
		point++;
	}
	return (1);
}

int			ft_clear_tetro(int **grid, t_tetro tetro, size_t size)
{
	size_t	point;

	point = 0;
	if (ft_x_max(tetro) >= size || ft_y_max(tetro) >= size)
		return (-1);
	point = 0;
	while (point < 4)
	{
		grid[tetro.oct[point].y][tetro.oct[point].x] = '.';
		point++;
	}
	return (1);
}
