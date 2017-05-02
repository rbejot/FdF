/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:11:00 by rbejot            #+#    #+#             */
/*   Updated: 2016/04/20 18:24:49 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define Z 6
# define X 7
# define W 13
# define S 1
# define A 0
# define D 2
# define SPACE 49
# define RETURN 36
# define C 8
# define V 9
# define N1 18
# define N2 19
# define N3 20
# define N4 21

typedef struct	s_liste
{
	int				*tab;
	int				length;
	struct s_liste	*next;
}				t_liste;

typedef struct	s_coor
{
	int x;
	int y;
	int z;
	int new_x;
	int new_y;
	int nb_points;
}				t_coor;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_liste	*begin_list;
	char	*line;
	int		fd;
	int		size;
	int		x;
	int		y;
	int		c;
	int		len;
	int		nb_points;
	double	fac;
	double	alpha;
	double	omega;
	double	up;
	int		origin_x;
	int		origin_y;
	t_coor	*e;
	t_liste	*tmp;
	int		color;
	t_point	i;
	t_point	j;
	int		index;
	int		border;
}				t_env;

typedef struct	s_vector
{
	float	x;
	float	y;
	float	inter;
}				t_vector;

t_env			stock_points(t_env *env);
t_env			rotate_map(t_env *env);
int				ft_wrline(t_env *env);
float			ft_isneg(float i);
float			ft_revneg(float	i);
int				key_press(int keycode, t_env *env);
t_env			init_env(t_env *env);
t_env			read_fdf(char **av, t_env *env);
void			send_points(t_env *env);
void			usage(int i);
int				key_rotate(int keycode, t_env *env);
int				key_zoom(int keycode, t_env *env);
int				key_move(int keycode, t_env *env);
int				key_color(int keycode, t_env *env);
int				key_height(int keycode, t_env *env);
#endif
