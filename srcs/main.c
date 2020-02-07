/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:13:09 by oelaina           #+#    #+#             */
/*   Updated: 2020/02/05 00:21:02 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		count_finpaths(t_finpaths *lst)
{
	int count;
	t_finpaths *tmp;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int		count_path(t_path *lst)
{
	int count;
	t_path *tmp;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int		check(t_finpaths *paths, int i)
{
	int			result;
	int			cursteps;
	int			j;
	t_finpaths	*cur;

	j = 0;
	result = 0;
	cur = paths;
	while (j++ < i)
		cur = cur->next;
	cursteps = count_path(cur->path);
	while (i > 0)
	{
		cur = paths;
		j = 0;
		i--;
		while (j++ < i)
			cur = cur->next;
		result += cursteps - count_path(cur->path);
	}
	return (result);
}

int		optimal_paths(t_finpaths *paths, int ants)
{
	int		i;
	int		opsize;
	int		size;
	i = 0;
	opsize = 0;
	size = count_finpaths(paths);
	if (size == 1)
		return (1);
	while (i < size)
	{
		if (ants > check(paths, i))
			opsize++;
		else
			break ;
		i++;
		ants--;
	}
	return (opsize);
}


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
	/*t_cell *temp = map->cells;
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
		ant_cross(map, map->count, optimal_paths(map->paths, map->count));
	else
		error_msg();
	return (0);
}
