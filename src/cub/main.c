/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:54:06 by anolivei          #+#    #+#             */
/*   Updated: 2021/03/16 23:25:16 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int initialize_window(t_all *all)
{
	if ((all->mlx.init = mlx_init()) == 0)
	{
		ft_putstr_fd("Error initializing minilibX\n", 1);
		return (FALSE);
	}
	if ((all->mlx.window = mlx_new_window(all->mlx.init, WIN_WIDTH, WIN_HEIGHT,
		"anolivei")) == 0)
	{
		ft_putstr_fd("Error initializing window\n", 1);
		return (FALSE);
	}
	if ((all->img.img_ptr = mlx_new_image(all->mlx.init,
		WIN_WIDTH + 1, WIN_HEIGHT + 1)) == 0)
	{
		ft_putstr_fd("Error initializing new image\n", 1);
		return (FALSE);
	}
	return (TRUE);
}

void	setup(t_player *player)
{
	player->x = WIN_WIDTH / 2;
	player->y = WIN_HEIGHT / 2;
	player->width = 6;
	player->height = 6;
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->rot_angle = 45 * (PI / 180);
	player->walk_speed = 10;
	player->turn_speed = 5 * (PI / 180);
}

void	render(t_all *all)
{
	render_map(all);
	render_player(all);
	mlx_put_image_to_window(all->mlx.init, all->mlx.window,
		all->img.img_ptr, 0, 0);
	render_rays(all);
}

int		main(void)
{
	t_all	all;

	initialize_window(&all);
	setup(&all.player);
	process_input(&all);
	cast_all_rays(&all);
	mlx_loop(all.mlx.init);
	return (0);
}