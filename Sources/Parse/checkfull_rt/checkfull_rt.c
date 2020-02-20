/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfull_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:06:53 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/17 12:46:07 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_res(t_res *res)
{
	if (res->x < 0)
		res->x = 500;
	else if (res->x > MAXX)
		res->x = MAXX;
	if (res->y < 0)
		res->y = 500;
	else if (res->y > MAXY)
		res->y = MAXY;
	
}

int			checkfull_rt(t_obj *obj)
{
	if (!check_alight(obj->alight_list))
		return (0);
	if (!check_cam(obj->cam_list))
		return (0);
	if (!check_light(obj->light_list))
		return (0);
	if (!check_plane(obj->plane_list))
		return (0);
	//if (!check_cyl(obj->cyl_list))
	//	return (0);
	check_res(obj->res);
	return (1);
}