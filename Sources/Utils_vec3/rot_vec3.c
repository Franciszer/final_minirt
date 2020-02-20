/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:56:02 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/17 14:09:55 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vec3	get_rot_vec3(t_vec3 *c1, t_vec3 *c2, t_vec3 *c3, t_vec3 rot, t_vec3 dir)
{
	t_vec3	v;
	double	c;
	double	s;
	double	r;

	v = cross_vec3(dir, rot);
	c = dot(rot, dir);
	s = pow(norm(v), 2);
	r = ((1 -c) / s);
	(*c1) = get_vec3(-r * (pow(v.y, 2) + pow(v.z, 2)) + 1, r * v.x * v.y - v.z, r * v.x * v.z + v.y);
	(*c2) = get_vec3(r * v.x * v.y + v.z, -r * pow(v.x, 2) + pow(v.z, 2) + 1, r * v.y * v.x - v.x);
	(*c3) = get_vec3(r * v.x * v.z - v.y, r * v.y * v.z - v.x, -r * (pow(v.x, 2) + pow(v.y, 2)) + 1);
	return (*c1);
}

// t_vec3			rot_vec3(t_vec3 o, t_vec3 dir, t_vec3 rot)
// {
// 	t_vec3	c1;
// 	t_vec3	c2;
// 	t_vec3	c3;
// 	t_vec3	prev;
// 	t_vec3	check;

// 	check = cross_vec3(dir, rot);
// 	if (dir.x != rot.x || dir.y != rot.y || dir.z != rot.z)
// 	{
// 		if (!check.x && !check.y && !check.z)
// 		{
// 			o = opf_vec3(o, '*', -1);
// 		}
// 		else
// 		{
// 			prev = o;
// 			get_rot_vec3(&c1, &c2, &c3, rot, dir);
// 			o = get_vec3(dot(c1, prev), dot(c2, prev), dot(c3, prev));
// 		}
// 	}
// 	return (o);
// }

t_vec3			rot_vec3(t_vec3 o, t_vec3 dir, t_vec3 rot)
{
	t_vec3	c1;
	t_vec3	c2;
	t_vec3	c3;
	t_vec3	prev;
	t_vec3	check;

	check = cross_vec3(dir, rot);
	if (dir.x != rot.x || dir.y != rot.y || dir.z != rot.z)
	{
		if (!check.x && !check.y && !check.z)
		{
			o = opf_vec3(o, '*', -1);
		}
		else
		{
			prev = o;
			get_rot_vec3(&c1, &c2, &c3, rot, dir);
			o = get_vec3(dot(c1, prev), dot(c2, prev), dot(c3, prev));
		}
	}
	return (o);
}
