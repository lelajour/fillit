/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 14:04:56 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 15:23:34 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

static void		tmp_index(t_tetris *lst)
{
	int i;

	while (lst != NULL)
	{
		if (!(lst->tmp_x = (int*)malloc(sizeof(int) * 4)))
			return ;
		if (!(lst->tmp_y = (int*)malloc(sizeof(int) * 4)))
			return ;
		i = 0;
		while (i < 4)
		{
			lst->tmp_x[i] = lst->x[i];
			lst->tmp_y[i] = lst->y[i];
			i++;
		}
		lst = lst->next;
	}
}

int				main(int ac, char **av)
{
	int			nb_tetri;
	t_tetris	*l_tetris;
	int			i;

	nb_tetri = 0;
	i = -1;
	if (ac != 2)
	{
		ft_putendl("usage: fillit tetriminos(.txt)");
		exit(TRUE);
	}
	else if (!(nb_tetri = fillit_check_file(av[1])))
		ft_fail();
	if (l_check(av[1]) != TRUE)
		ft_fail();
	if (!(l_tetris = fillit_store(av[1])))
		ft_fail();
	tmp_index(l_tetris);
	ft_return(l_tetris, nb_tetri);
	return (0);
}
