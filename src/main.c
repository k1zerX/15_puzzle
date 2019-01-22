/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:55:31 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/22 22:05:00 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle_15.h"

char				ft_exit(int **a, int *b, int *c);
char				up(int **map, int *y, int *x);
char				down(int **map, int *y, int *x);
char				left(int **map, int *y, int *x);
char				right(int **map, int *y, int *x);

char				(*g_cmds[])(int **, int *, int *) =
{
	&ft_exit,
	&up,
	&down,
	&left,
	&right,
	NULL
};

char	ft_exit(int **a, int *b, int *c)
{
	(void)a;
	(void)b;
	(void)c;
	exit(0);
}

t_list	*lst_get(t_list *start, int n)
{
	t_list	*tmp;
	t_list	*buf;
	int		i;

	tmp = start;
	while (i-- > 0)
	{
		buf = tmp;
		tmp = tmp->next;
	}
	buf->next = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

void	lst_add(t_list *start, int n)
{
	t_list	*tmp;
	t_list	*lst;

	tmp = malloc(sizeof(*tmp));
	tmp->n = n;
	tmp->next = start;
	lst = start;
	while (lst->next != start)
		lst = lst->next;
	lst->next = tmp;
}

int		rng_x(int interval)
{
	static t_list	*nbrs = NULL;
	t_list			*tmp;
	int				i;

	if (!nbrs)
	{
		nbrs = malloc(sizeof(*nbrs));
		nbrs->next = nbrs;
		nbrs->n = 0;
		i = interval;
		while (i-- > 1)
			lst_add(nbrs, i);
	}
	tmp = lst_get(nbrs, rand() % interval);
	i = tmp->n;
	//free(tmp);
	return (i);
}

int		**new_map(int n, int m)
{
	int		**map;
	int		i;
	int		j;

	map = malloc(n * sizeof(*map));
	i = n;
	while (i-- > 0)
	{
		map[i] = malloc(m * sizeof(**map));
		j = m;
		while (j-- > 0)
			map[i][j] = rng_x(n * m);
	}
	return (map);
}

char	is_solved(int **map, int n, int m)
{
	int		i;
	int		j;

	i = n;
	while (i-- > 0)
	{
		j = m;
		while (j-- > 0)
			if (((i * n + j + 1) % (n * m)) != map[i][j])
				return (0);
	}
	return (1);
}

void	print_map(int **map, int n, int m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < m)
			printf("----");
		printf("-\n");
		j = -1;
		while (++j < m)
			if (map[i][j])
				printf("|%2d ", map[i][j]);
			else
				printf("|   ");
		printf("|\n");
	}
	j = -1;
	while (++j < m)
		printf("----");
	printf("-\n");
}

int		main(void)
{
	int		**map;
	int		cmd;
	int		y;
	int		x;

	map = new_map(Y_SIZE, X_SIZE);
	y = Y_SIZE;
	while (y-- > 0)
	{
		x = X_SIZE;
		while (x-- > 0 && map[y][x])
			if (!map[y][x])
				break ;
		if (!map[y][x])
			break ;
	}
	while (!is_solved(map, Y_SIZE, X_SIZE))
	{
		//scanf("%d", &cmd);
		print_map(map, Y_SIZE, X_SIZE);
		printf("usage:\n1) UP\n2) DOWN\n3) LEFT\n4) RIGHT\n0) exit\n");
		if (!scanf("%d", &cmd))
			cmd = 0;
		if (cmd < 0 || cmd > 4)
			printf("wrong command\n");
		else if (!(g_cmds[cmd](map, &y, &x)))
			printf("bad action\n");
	}
	print_map(map, Y_SIZE, X_SIZE);
	printf("Congrats!\n");
	return (0);
}
