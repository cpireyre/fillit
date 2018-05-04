/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 08:22:33 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/04 07:54:54 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_block(const char *block)
{
	int		i;
	size_t	symbols[4];

	i = 0;
	ft_bzero(symbols, sizeof(size_t) * 4);
	while (i < 20)
	{
		if (block[i] == '.' && ((i + 1) % 5))
			symbols[0]++;
		else if (block[i] == '#' && ((i + 1) % 5))
		{
			symbols[1]++;
			symbols[3] += ((i - 1) >= 0 && block[i - 1] == '#') +
				((i + 1) <= 20 && block[i + 1] == '#')
				+ ((i - 5) >= 0 && block[i - 5] == '#') +
				((i + 5) <= 20 && block[i + 5] == '#');
		}
		else if (block[i] == '\n' && !((i + 1) % 5))
			symbols[2]++;
		else
			return (0);
		i++;
	}
	return (symbols[0] == 12 && symbols[1] == 4 && symbols[2]
			&& symbols[3] >= 6);
}

int		ft_check_file(const char *buf)
{
	size_t	o;
	size_t	len;

	o = 0;
	len = ft_strlen(buf);
	while (o < len)
	{
		if (!ft_check_block(buf + o))
			return (0);
		o += 21;
	}
	return (1);
}

char	*ft_get_file(const char *file)
{
	int		filedesc;
	int		ret;
	char	*file_content;
	char	buf[547];

	filedesc = open(file, O_RDONLY);
	if (filedesc < 0)
		ft_exit_error();
	ft_bzero(buf, sizeof(char) * 547);
	ret = read(filedesc, &buf, 546);
	if (ret % 21 != 20 || !ft_check_file(buf))
		ft_exit_error();
	file_content = ft_strdup(buf);
	return (file_content);
}
