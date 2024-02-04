#include "my_mat.h"

void initMatrix(int mat[][MAT_SIZE])
{
    int i = 0, j = 0;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            scanf("%d", mat[i][j]);
        }
    }
}

int floydWarshallAlgorithm(int mat[][MAT_SIZE], int i, int j)
{
    int i = 0, j = 0, k = 0;
    int matCopy[MAT_SIZE][MAT_SIZE] = {{0}};

    for(int i = 0; i < MAT_SIZE; i++)
    {
        for(int j = 0; j < MAT_SIZE; j++)
        {
            matCopy[i][j] = mat[i][j];
        }
    }

}
