/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:48:35 by tcase             #+#    #+#             */
/*   Updated: 2019/09/14 22:48:40 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove(t_list **alist, t_list **list, void (*del)())
{
	t_list	*last;
	t_list	*curr;
	t_list	*tmp;

	curr = *alist;
	while (curr)
	{
		if (curr == *list)
		{
			if (curr == *alist)
				*alist = curr->next;
			else
				last->next = curr->next;
			tmp = curr;
			curr = curr->next;
			del(tmp->content, tmp->content_size);
			ft_memdel((void**)&tmp);
		}
		else
		{
			last = curr;
			curr = curr->next;
		}
	}
}
