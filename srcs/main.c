/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:13:09 by oelaina           #+#    #+#             */
/*   Updated: 2020/01/18 22:10:58 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

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
/*	t_cell *temp = map->cells;
	t_neib *teemp;
	while (temp)
	{
		printf("CELL:%s\n", temp->name);
		teemp = temp->next_neib;
		while(teemp)
		{
			printf("NEIB:%s\n", map->arr_cell[teemp->index]->key);
			teemp = teemp->next;
		}
		printf("\n");
		temp = temp->next;
	}*/
	bhandari_algo(map);
	/*t_path *tmp;
	while (map->paths)
	{
		tmp = map->paths->path;
		while (tmp)
		{
			printf("ROUTE: %s\n", tmp->cell->name);
			tmp = tmp->next;
		}
		printf("NEXT\n");
		map->paths = map->paths->next;
	}
	t_path *teeemp;
	while (map->rev_paths)
	{
		teeemp = map->rev_paths->path;
		while (teeemp)
		{
			ft_printf("DEL: %s\n", teeemp->cell->name);
			teeemp = teeemp->next;
		}
		printf("REV\n");
		map->rev_paths = map->rev_paths->next;
	}
	temp = map->cells;
	while (temp)
	{
		printf("CELL:%s\n", temp->name);
		teemp = temp->next_neib;
		while(teemp)
		{
			printf("NEIB:%s\n", map->arr_cell[teemp->index]->key);
			teemp = teemp->next;
		}
		printf("\n");
		temp = temp->next;
	}*/
	if (map->paths)
		ant_cross(map, map->count);
	else
		error_msg();
	return (0);
}
