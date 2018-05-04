/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:05:03 by cpireyre          #+#    #+#             */
/*   Updated: 2018/04/27 07:27:05 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char	*new;

	if (!(new = ft_memalloc(len + 1)))
		return (NULL);
	ft_bzero(new, sizeof(char) * (len + 1));
	return (new);
}
