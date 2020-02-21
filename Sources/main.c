/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:10:32 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/21 23:08:09 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		main(int ac, char **av)
{
	t_obj		*obj;

	if (!is_rtfile(av[1]) || !(obj = parse_rt(av[1])))
		return (0);
	if (ac == 2)
		display_rt(obj);
	else if (ac == 3)
	{
		if (!ft_strncmp(av[2], "--save", ft_strlen("--save")))
		{
			get_inters_rt(obj);
			if (!write_bmp(obj))
				ft_printf("ERROR WRITING\n");
			else
				ft_printf("SUCCESS!\n");
		}
		else
			print_error("Invalid argument\n");
		system("leaks miniRT");
		free_obj_rt(obj);
	}
	else
		ft_printf("Wrong number of arguments\n");
	return (0);
}
