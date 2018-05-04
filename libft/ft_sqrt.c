/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 11:27:20 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/04 07:28:14 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int n)
{
	int		sq;

	if (n < 0)
		return (0);
	else if (n < 2)
		return (n);
	sq = 1;
	while (sq * sq < n)
		sq++;
	return (sq);
}