/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:13:48 by oelaina           #+#    #+#             */
/*   Updated: 2020/01/18 19:54:29 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	check_int(char *line, char *line2)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0)
			error_msg();
		i++;
	}
	i = 0;
	while (line2[i] != '\0')
	{
		if (ft_isdigit(line2[i]) == 0)
			error_msg();
		i++;
	}
}

void			set_cell(t_cell *cell, char *line)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(line, ' ');
	cell->name = ft_strdup(arr[0]);
	check_int(arr[1], arr[2]);
	cell->x = ft_atoi(arr[1]);
	cell->y = ft_atoi(arr[2]);
	cell->is_visited = 0;
	cell->distance = 0;
	cell->ant = 0;
	cell->prev = NULL;
	cell->next = NULL;
	cell->sp_next = NULL;
	cell->next_neib = NULL;
	while (arr[i])
	{
		free(arr[i]);
		if (i > 2)
			error_msg();
		i++;
	}
	free(arr[i]);
	free(arr);
}

t_cell			*init_cell(void)
{
	t_cell *cell;

	if (!(cell = (t_cell *)malloc(sizeof(t_cell))))
		exit(1);
	cell->next_neib = NULL;
	cell->next = NULL;
	return (cell);
}
