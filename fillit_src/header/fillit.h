/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 13:38:50 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 16:16:46 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 700
# define TRUE 0
# define FALSE 1

typedef struct			s_lfillit
{
	char				**tetris;
	char				pause;
	int					*x;
	int					*tmp_x;
	int					*y;
	int					*tmp_y;

	struct s_lfillit	*next;
}						t_tetris;

void					ft_delete(t_tetris *lst, char **tab, int nb_tab);
int						ft_ifposible(t_tetris *lst, char **tab, int nb_tab);
void					ft_increase(int *tab);
void					x_reset(t_tetris *lst);
void					y_reset(t_tetris *lst);
int						ft_memshr(int *tab, int size);
int						putintab(t_tetris *lst, char **tab, int nb_tab);
char					**new_tab(int nb_tab);
int						ft_algo(t_tetris *lst, char **tab, int nb_tab);
int						is_ok(t_tetris *lst, char **tab, int nb_tab);
int						ft_strlenc(char *str, int c);
char					**ft_return(t_tetris *lst, int nb_tetris);
t_tetris				*pos_tetris(t_tetris *lst);
char					**swap_empty(char **tab);
t_tetris				*new_l(char *str);
t_tetris				*fillit_store(char *str);
int						ft_ltab(char **tab);
void					ft_fail(void);
int						l_check(char *str);
int						valid_tetri(char *str);
int						fillit_read(char str[BUFF_SIZE + 1]);
int						check_tfile(char **tab);
int						fillit_check_file(char *file);
int						check_tetri(char **tab);

#endif
