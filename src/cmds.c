/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:43:39 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/22 21:23:20 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle_15.h"

void	swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

char	up(int **map, int *y, int *x)
{
	if (*y >= Y_SIZE || *x >= X_SIZE || *y - 1 < 0 || *x < 0)
		return (0);
	swap(map[*y] + *x, map[*y - 1] + *x);
	(*y)--;
	return (1);
}

char	down(int **map, int *y, int *x)
{
	if (*y + 1 >= Y_SIZE || *x >= X_SIZE || *y < 0 || x < 0)
		return (0);
	swap(map[*y] + *x, map[*y + 1] + *x);
	(*y)++;
	return (1);
}

char	left(int **map, int *y, int *x)
{
	if (*y >= Y_SIZE || *x >= X_SIZE || *y < 0 || *x - 1 < 0)
		return (0);
	swap(map[*y] + *x, map[*y] + *x - 1);
	(*x)--;
	return (1);
}

char	right(int **map, int *y, int *x)
{
	if (*y >= Y_SIZE || *x + 1 >= X_SIZE || *y < 0 || *x < 0)
		return (0);
	swap(map[*y] + *x, map[*y] + *x + 1);
	(*x)++;
	return (1);
}
