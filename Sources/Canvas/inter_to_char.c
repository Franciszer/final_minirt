/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_to_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:47:16 by qfeuilla          #+#    #+#             */
/*   Updated: 2020/02/20 12:39:58 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

unsigned char	*inter_to_char(t_obj *obj, t_inter **inter)
{
	int	i;
	int	j;
	int	z;
	int	x;
	int	y;
	unsigned char *colors;

	z = obj->res->x * obj->res->y * 3;
	colors = malloc(sizeof(char) * z);
	i = 0;
	x = obj->res->x;
	y = obj->res->y;
	//z = 0;
	while (i < y)
	{
		j = x - 1;
		while (j != -1)
		{
			colors[--z] = inter[i][j].rgb[0];
			colors[--z] = inter[i][j].rgb[1];
			colors[--z] = inter[i][j].rgb[2];
			j--;
		}
		i++;
	}
	return (colors);
}
