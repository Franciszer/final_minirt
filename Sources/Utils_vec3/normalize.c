/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:59:52 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/17 11:17:00 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	normalize(t_vec3 v)
{
	double	norm3;

	norm3 = norm(v);
	if (norm3 != 1 && norm3)
		return (opf_vec3(v, '/', norm3));
	else
		return (v);
}
