/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:11:28 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/21 19:19:49 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

int		g_size_line;
int		g_bpp;
int		g_endian;

int		deal_key(int key, void *param)
{
	t_data	*data;

	data = (t_data*)param;
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		free_obj_rt(data->obj);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		system("leaks miniRT");
		exit(0);
	}
	if (key == 48)
	{
		data->inter_n[0]++;
		get_img_rt(data->cols, data->obj,\
				which_inter(data->obj->inter_list, data->inter_n), data);
	}
	return (1);
}

void	init_mlxdata(t_data *data, t_obj *obj)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,\
		obj->res->x, obj->res->y, "miniRT");
}

void	get_img_rt(unsigned char *colors, t_obj *obj, t_inter **inter, t_data *data)
{
	int	i;
	int	j;
	int	z;
	int	x;
	int	y;

	i = 0;
	z = 0;
	x = (int)obj->res->x;
	y = (int)obj->res->y;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			colors[z++] = inter[i][j].rgb[2];
			colors[z++] = inter[i][j].rgb[1];
			colors[z++] = inter[i][j].rgb[0];
			colors[z++] = 0;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

t_inter	**which_inter(t_list *inter_list, int *n)
{
	t_list	*nav;
	int		i;

	i = 0;
	nav = inter_list; 
	if (*n < 0)
		*n = ft_lstlen(inter_list) - 1;
	else if (*n > ft_lstlen(inter_list) - 1)
		*n = 0;
	i = 0;
	while (nav->next)
	{
		if (i == *n)
		{
			return ((t_inter**)nav->content);
		}
		nav = nav->next;
		i++;
	}
	return ((t_inter**)nav->content);
}

int		display_rt(t_obj *obj)
{
	t_data	data;
	t_inter	**inter;
	int		inter_n;

	init_mlxdata(&data, obj);
	inter_n = 0;
	data.inter_n = &inter_n;
	data.img_ptr = mlx_new_image(data.mlx_ptr,\
			(int)obj->res->x, (int)obj->res->y);
	data.cols = (unsigned char*)mlx_get_data_addr(data.img_ptr,\
			&g_bpp, &g_size_line, &g_endian);
	data.obj = obj;
	if (!(get_inters_rt(obj)))
		return (0);
	inter = which_inter(obj->inter_list, data.inter_n);
	get_img_rt(data.cols, obj, inter, &data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	return (1);
}
