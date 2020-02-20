/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:37:51 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/17 14:25:29 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*get_bmpname(int n)
{
	char	*path;
	char	*name;

	if (!(name = ft_strjoin("img", ft_itoa(n))))
		return (NULL);
	if (!(path = ft_strjoin(BMPPATH, ft_strjoin(name, ".bmp"))))
		return (NULL);
	return (path);
}

int			save_image_rt(t_obj *obj)
{
	t_inter	**inter;
	char	*name;
	int		n;
	t_list	*nav;
	char	*cols;

	n = 0;
	if (!get_inters_rt(obj))
		return (0);
	nav = obj->inter_list;
	while (nav)
	{
		inter = (t_inter**)nav->content;
		if (!(cols = inter_to_char(obj, inter)))
			return (0);
		if (!(name = get_bmpname(n)))
			return (0);
		if (!export_as_bmp(name, (unsigned char*)cols, obj->res->x, obj->res->y))
			return (0);
		n++;
		nav = nav->next;
	}
	return (1);
}
