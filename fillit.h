/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:23:06 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/01 16:11:08 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetro
{
	t_point oct[4];
	char	letter;
}				t_tetro;

char			*ft_get_file(const char *file);
int				ft_read_block(const char *block);
void			ft_print_tetro(t_tetro tetro);
void			ft_exit_error(void);
t_tetro			ft_create_tetro(const char *valid_block, char letter);
t_point			ft_build_point(int a, int b);
void			ft_normalize(t_tetro *tetro);
int				ft_check_block(const char *block);
t_list			*ft_create_list(const char *buffer);
int				**create_grid(size_t size);
void			print_grid(int **grid, size_t size);
int				ft_place_tetro(int **grid, t_tetro tetro, size_t size);
int				ft_shift(t_tetro *tetro, size_t size);
size_t			ft_x_min(t_tetro tetro);
size_t			ft_x_max(t_tetro tetro);
size_t			ft_y_min(t_tetro tetro);
size_t			ft_y_max(t_tetro tetro);
int				fillit(int ***grid, t_list *tetro, size_t *size, int var);
int				**enlarge_your_grid(int **grid, size_t current_size);
int				ft_clear_tetro(int **grid, t_tetro tetro, size_t size);
void			ft_chain_normalize(t_list *tetro);

#endif
