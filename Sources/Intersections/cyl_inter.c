/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:42:10 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/19 10:57:11 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter		cyl_iter(t_list *cyl_list, t_vec3 cam_o, t_vec3 d, t_inter inter_min)
{
	t_list		*nav;
	t_cyl		*cyl;
	t_inter		inter_curr;

	nav = cyl_list;
	while (nav)
	{
		cyl = (t_cyl*)nav->content;
		inter_curr = cyl_inter(cyl, cam_o, d);
		if (inter_curr.d_to_o != INIT_D && (inter_min.d_to_o == INIT_D||\
									inter_curr.d_to_o < inter_min.d_to_o))
			inter_min = inter_curr;
		nav = nav->next;
	}
	return (inter_min);
}

t_inter		cyl_inter(t_cyl *cyl, t_vec3 o, t_vec3 d)
{
	t_vec3	top;
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	t;

	top = op_vec3(op_vec3(cyl->o, '+', opf_vec3(cyl->d, '*', cyl->h)), '-', cyl->o);
	oc = op_vec3(o, '-', cyl->o);
	double	top2 = dot(top, top); //caca
	double	top_d = dot(top, d);  //card
	double	top_oc = dot(top, oc); //caoc
	a = top2 - pow(top_d, 2);
	b = top2 * dot(oc, d) - (top_oc * top_d);
	c = top2 * dot(oc, oc) - pow(top_oc, 2) - ((pow(cyl->r, 2)) * top2);
	double h = pow(b, 2) - (a * c);
	if (h < 0)
		return (get_inter(o, o, 0, NULL));
	h = sqrt(h);
	t = (-b -h) / a;
	double	y = top_oc + t * top_d;
	if (y > 0 && y < top2 && t > 0)
		return(get_inter(op_vec3(o, '+', opf_vec3(d, '*', t)), o, CY, (void*)cyl));
	t = (-b + h) / a;
	y = top_oc + t * top_d;
	if (y > 0 && y < top2 && t > 0)
		return(get_inter(op_vec3(o, '+', opf_vec3(d, '*', t)), o, CY, (void*)cyl));
	return (get_inter(o, o, 0, NULL));
}
