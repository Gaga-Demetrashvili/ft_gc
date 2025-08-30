/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemetra <gdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:20:18 by gdemetra          #+#    #+#             */
/*   Updated: 2025/08/30 23:53:24 by gdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gb_collect.h"

int	main(void)
{
	init_gc(malloc(sizeof(t_gc)));

	printf("Testing single allocation...\n");
	int *a = gc_malloc(sizeof(int));
	if (!a)
		return (1);
	*a = 42;
	printf("Value of a: %d\n", *a);

	// free single
	gc_free(a);

	printf("Testing array allocation...\n");
	int *arr = gc_malloc(5 * sizeof(int));
	if (!arr)
		return (1);
	for (int i = 0; i < 5; i++)
		arr[i] = i * 10;
	printf("Array: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("Testing 2D array allocation...\n");
	int **matrix = gc_malloc(3 * sizeof(int *));
	for (int i = 0; i < 3; i++)
		matrix[i] = gc_malloc(3 * sizeof(int));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = i * 10 + j;

	printf("Matrix:\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	printf("Testing 3D array allocation...\n");
	int ***cube = gc_malloc(3 * sizeof(int **));

	for (int i = 0; i < 3; i++)
	{
		cube[i] = gc_malloc(3 * sizeof(int *));
		for (int j = 0; j < 3; j++)
		{
			cube[i][j] = gc_malloc(3 * sizeof(int));
			for (int k = 0; k < 3; k++)
				cube[i][j][k] = i * 100 + j * 10 + k;
		}
	}

	printf("Cube:\n");
	for (int i = 0; i < 3; i++)
	{
		printf("Layer %d:\n", i);
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
				printf("%3d ", cube[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}

	printf("Freeing all allocations...\n");
	gc_free_all();

	printf("All done! Use valgrind to check for leaks.\n");
	free(ft_gc());
	return (0);
}