/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:52:54 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/28 11:52:58 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <string.h>

typedef	struct	s_fdf
{
	int			s_x;
	int			s_y;
	int			n_x;
	int			n_y;
	int			num;
	void		*mlx;
	void		*win;
	int			**dp_int;
	int			hight;
	int			width;
	int			z;
}				t_fdf;

void			error_output_massage(char *str);
void			ft_free(char **str);
void			free_struct(t_fdf *fdf);
void			read_file(t_fdf *fdf, int fd);
void			window_start(t_fdf *esc_keypress, char *argv);
void			map_draw(t_fdf *draw);
void			fix_cord(int *pix, int *tab, int *y0, int *x0);
void			draw_line(t_fdf *fdf, int *tabxy);
void			start_algoritm(t_fdf *fdf);
void			draw_lines(t_fdf *fdf, int x, int y);
void			map_draw(t_fdf *fdf);
int				esc_keypress(int esc_keypresscode, t_fdf *fdf);
void			struct_init(t_fdf *fdf);
void			check_error(char *line, t_fdf *fdf);
void			fdf_check(t_fdf *fdf, int fd);
void			write_coor_int_arr(t_fdf *fdf, char **line);
int				get_next_line(const int fd, char **line);
size_t			ft_strlen(const char *str);
char			**ft_strsplit(char const *s, char c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			line(t_fdf *win, int *x_y_x1_x2);
void			line_cont(t_fdf *win, int *x_y_x1_x2, int *length_x_y);
void			line_cont_next(t_fdf *win, int *x_y_x1_x2, int *length_x_y);
void			err_on_wrong_fd(char *argv, int argc, t_fdf *fdf);
void			draw_horizont(t_fdf *fdf, int x, int y, int *tabxy);
void			draw_vertical(t_fdf *fdf, int x, int y, int *tabxy);

#endif
