/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_tab.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:49:11 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 15:23:40 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

char	**new_tab(int nb_tab)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_tab) + 1)))
		return (NULL);
	while (i < nb_tab)
	{
		tab[i] = ft_strnew(nb_tab);
		ft_memset(tab[i], '.', nb_tab);
		i++;
	}
	return (tab);
}

void	ft_delete(t_tetris *lst, char **tab, int nb_tab)
{
	int i;

	i = 0;
	while (i < nb_tab * nb_tab)
	{
		if (tab[i / nb_tab][i % nb_tab] == lst->pause)
			tab[i / nb_tab][i % nb_tab] = '.';
		i++;
	}
}
