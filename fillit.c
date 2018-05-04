/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:22:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/01 16:29:08 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		fillit(int ***grid, t_list *tetro, size_t *size, int var)
{
	t_tetro	*tmp;

	if (!tetro)
		return (1);
	tmp = (t_tetro*)tetro->content;
	if (!(var = ft_place_tetro(*grid, *tmp, *size)))
		if (!(ft_shift(tetro->content, *size) && fillit(grid, tetro, size, 0)))
			ft_clear_tetro(*grid, *(t_tetro*)(tetro->content), *size);
		else
			return (1);
	else if (var == 1)
	{
		if (fillit(grid, tetro->next, size, 0) != 0)
			return (1);
		ft_clear_tetro(*grid, *tmp, *size);
		if (ft_shift(tmp, *size) && tetro->next)
			ft_chain_normalize(tetro->next);
	}
	else if ((*tmp).letter != 'A')
		return (0);
	else if ((*grid = enlarge_your_grid(*grid, ++(*size))))
		ft_chain_normalize(tetro);
	return (fillit(grid, tetro, size, 0));
}

int		main(int argc, char **argv)
{
	char	*buffer;
	t_list	*list;
	size_t	tetroes;
	int		**grid;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (1);
	}
	buffer = ft_get_file(argv[1]);
	list = ft_create_list(buffer);
	tetroes = ft_sqrt(4 * ft_lstdepth(list));
	grid = create_grid(tetroes);
	fillit(&grid, list, &tetroes, 0);
	print_grid(grid, tetroes);
	return (0);
}
