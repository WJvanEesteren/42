/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <vtouffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:07:14 by vtouffet          #+#    #+#             */
/*   Updated: 2018/02/09 11:57:25 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../includes/minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int		ft_is_exec(char *path)
{
	struct stat path_stat;

	lstat(path, &path_stat);
	if (!S_ISREG(path_stat.st_mode) && !S_ISLNK(path_stat.st_mode))
		return (0);
	return (path_stat.st_mode & S_IXUSR ? 1 : -1);
}
