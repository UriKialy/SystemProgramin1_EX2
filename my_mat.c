#include "my_mat.h"

void initMatrix(int mat[][MAT_SIZE])
{
    int i = 0, j = 0;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

int floydWarshallAlgorithm(int mat[][MAT_SIZE], int a, int b)
{
    int i = 0, j = 0, k = 0;
    int matCopy[MAT_SIZE][MAT_SIZE] = {{0}};

    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            matCopy[i][j] = mat[i][j];
        }
    }

    for (k = 0; k < MAT_SIZE; k++)
    {
        for (i = 0; i < MAT_SIZE; i++)
        {
            for (j = 0; j < MAT_SIZE; j++)
            {
                //original algorithm uses infinity where there's no edge -- here we add the distance for that case
                if (matCopy[i][j] == 0 && (i != j) && (matCopy[i][k] != 0 && matCopy[k][j] != 0))
                {
                    matCopy[i][j] = matCopy[i][k] + matCopy[k][j];
                }
                //regular addition according to the original algorithm
                else if (((matCopy[k][j] != 0) && (matCopy[i][k] != 0) && (matCopy[i][j] > (matCopy[i][k] + matCopy[k][j]))))
                {
                    matCopy[i][j] = matCopy[i][k] + matCopy[k][j];
                }
            }
        }
    }

    return matCopy[a][b];
}
