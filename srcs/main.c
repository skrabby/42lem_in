/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:13:09 by oelaina           #+#    #+#             */
/*   Updated: 2020/02/07 04:45:18 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map *map;

	map = init_map();
	parse_map(map);
	if (map->check_link == 0)
		error_msg();
	ft_putchar('\n');
	map->start = search_cell(map, map->start_str);
	map->end = search_cell(map, map->end_str);
	bhandari_algo(map);
	if (map->paths)
		ant_cross(map, map->count, optimal_paths(map->paths, map->count));
	else
		error_msg();
	return (0);
}
