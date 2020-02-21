/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:50:03 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 00:04:28 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(void)
{
	t_vec3	o;
	t_vec3	dir;
	t_vec3	rot;
	
	o = normalize(get_vec3(1,0,-1));
	dir = normalize(get_vec3(0,0,-1));
	rot = normalize(get_vec3(0,1,0));
	t_vec3 V = normalize(rot_vec3(o, dir, rot));
	printf("x: %f\n", o.x);
	printf("y: %f\n", o.y);
	printf("z: %f\n\n", o.z);
	printf("x: %f\n", V.x);
	printf("y: %f\n", V.y);
	printf("z: %f\n", V.z);
}
