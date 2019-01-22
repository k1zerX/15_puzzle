/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:55:31 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/22 20:01:42 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "15_puzzle.h"

int		rng_x(int interval)
{
	static t_list	*nbrs;

	if (!nbrs)
}

int		**new_map(int n, int m)
{
	int		**map;
	int		i;
	int		j;

	if (!(map = malloc(n * sizeof(*map))))
		return (NULL);
	i = n;
	while (i-- > 0)
	{
		if (!(map[i] = malloc(m * sizeof(**map))))
		{
			while (++i < n)
				free(map[i]);
			free(map);
			return (NULL);
		}
		j = m;
		while (j-- > 0)
			map[i][j] = rng_x(n * m);
	}
	return (map);
}

char	is_solved(char **map, int n, int m)
{
	int		i;
	int		j;

	i = n;
	while (i-- > 0)
	{
		j = m;
		while (j-- > 0)
			if (((i * n + j + 1) & 15) != map[i][j];
				return (0);
	}
	return (1);
}

void	print_map(int **map)
{
	
}

int		main(void)
{
	int		**map;
	char	cmd;

	map = new_map(Y_SIZE, X_SIZE);
	while (!is_solved(map, Y_SIZE, X_SIZE))
	{
		print_map(map, Y_SIZE, X_SIZE);
		printf("usage:\n1) UP\n2) DOWN\n3) LEFT\n4) RIGHT\n");
		scanf("%d", &cmd);
		while (!(cmd < 4 && g_cmds[cmd](map, y, x)))
		{
			printf("wrong command\n");
			printf("usage:\n1) UP\n2) DOWN\n3) LEFT\n4) RIGHT\n");
			scanf("%d", &cmd);
		}
	}
	print_map(map, Y_SIZE, X_SIZE);
	printf("Congrats!\n");
	return (0);
}
