/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:06:00 by anolivei          #+#    #+#             */
/*   Updated: 2021/03/07 23:49:10 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	move_render(t_all *all, int *walk_turn, int i)
{
	*walk_turn = i;
	move_player(&all->player);
	render(all);
}

int			key_press(int keycode, t_all *all)
{
	if (keycode == TAB_KEYM || keycode == TAB_KEYL)
		render(all);
	if (keycode == W_KEYM || keycode == W_KEYL)
		move_render(all, &all->player.walk_dir, +1);
	if (keycode == S_KEYM || keycode == S_KEYL)
		move_render(all, &all->player.walk_dir, -1);
	if (keycode == D_KEYM || keycode == D_KEYL)
		move_render(all, &all->player.turn_dir, +1);
	if (keycode == A_KEYM || keycode == A_KEYL)
		move_render(all, &all->player.turn_dir, -1);
	if (keycode == ESC_KEYM || keycode == ESC_KEYL)
		destroy_window(all);
	return (1);
}

int			key_release(int keycode, t_all *all)
{
	if (keycode == W_KEYM || keycode == W_KEYL)
		all->player.walk_dir = 0;
	if (keycode == S_KEYM || keycode == S_KEYL)
		all->player.walk_dir = 0;
	if (keycode == D_KEYM || keycode == D_KEYL)
		all->player.turn_dir = 0;
	if (keycode == A_KEYM || keycode == A_KEYL)
		all->player.turn_dir = 0;
	return (1);
}

int			destroy_window(t_all *all)
{
	mlx_clear_window(all->mlx.init, all->mlx.window);
	mlx_destroy_window(all->mlx.init, all->mlx.window);
	exit(0);
	return (1);
}

void		process_input(t_all *all)
{
	mlx_hook(all->mlx.window, 2, 1L << 0, key_press, all);
	mlx_hook(all->mlx.window, 3, 1L << 1, key_release, all);
	mlx_hook(all->mlx.window, 17, 1l << 17, destroy_window, all);
}
