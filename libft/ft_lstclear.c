/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:10:04 by frthierr          #+#    #+#             */
/*   Updated: 2020/01/27 15:23:13 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nav;
	t_list	*list;

	if (!(lst && del))
		return ;
	nav = *lst;
	while (nav)
	{
		list = nav->next;
		ft_lstdelone(nav, del);
		nav = list;
	}
}

