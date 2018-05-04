/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:40:15 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/01 14:25:29 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_list	*ft_create_list(const char *buffer)
{
	t_list	*tetro;
	t_tetro	piece;
	char	letter;
	size_t	offset;
	size_t	len;

	len = ft_strlen(buffer);
	offset = 0;
	letter = 'A';
	tetro = NULL;
	while (offset < len)
	{
		ft_bzero(&piece, sizeof(piece));
		piece = ft_create_tetro(buffer + offset, letter);
		offset += 21;
		ft_lstappend(&tetro, ft_lstnew(&piece, sizeof(piece)));
		letter++;
	}
	return (tetro);
}

void	ft_chain_normalize(t_list *tetro)
{
	while (tetro)
	{
		ft_normalize(tetro->content);
		tetro = tetro->next;
	}
}
