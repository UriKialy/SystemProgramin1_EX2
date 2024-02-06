#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>

#define MAT_SIZE 10

/*the function receives a matrix, returns an initiallized matrix*/
void initMatrix(int mat[][MAT_SIZE]);

/*the function will calculate the shortest path from i to j using the Floyd-Warshall algorithm*/
int floydWarshallAlgorithm(int mat[][MAT_SIZE], int, int);

#endif