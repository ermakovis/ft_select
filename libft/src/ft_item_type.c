/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:12:47 by tcase             #+#    #+#             */
/*   Updated: 2019/09/14 22:48:04 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_item_type(char *path)
{
	t_stat	stat;

	if (!path || !*path)
		return (-1);
	if (lstat(path, &stat) == -1)
		return (0);
	if (S_ISSOCK(stat.st_mode))
		return (1);
	if (S_ISDIR(stat.st_mode))
		return (2);
	if (S_ISLNK(stat.st_mode))
		return (3);
	if (S_ISFIFO(stat.st_mode))
		return (4);
	if (S_ISCHR(stat.st_mode))
		return (5);
	if (S_ISBLK(stat.st_mode))
		return (6);
	if (S_IXUSR & stat.st_mode || S_IXGRP & stat.st_mode ||\
			S_IXOTH & stat.st_mode)
		return (7);
	return (8);
}
