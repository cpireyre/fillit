/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:31:56 by hwolff            #+#    #+#             */
/*   Updated: 2018/05/01 08:10:45 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**create_grid(size_t size)
{
	int		**grid;
	size_t	i;
	size_t	j;

	i = 0;
	grid = ft_memalloc(sizeof(int*) * size);
	while (i < size)
		grid[i++] = ft_memalloc(sizeof(int) * size);
	i = 0;
	j = 0;
	while (i < size && !(j = 0))
	{
		while (j < size)
			grid[i][j++] = '.';
		i++;
	}
	return (grid);
}

void	print_grid(int **grid, size_t size)
{
	size_t	i;
	size_t	j;

	if (!grid || !size)
		return ;
	i = 0;
	j = 0;
	while (i < size && !(j = 0))
	{
		while (j < size)
			ft_putchar(grid[i][j] ? grid[i][j++] : '.');
		ft_putchar(++i ? '\n' : '\n');
	}
}

int		**enlarge_your_grid(int **grid, size_t size)
{
	if (grid && size)
	{
		ft_memdel((void**)grid);
		return (create_grid(size));
	}
	return (NULL);
}
