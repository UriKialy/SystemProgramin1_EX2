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
                if (matCopy[i][j] == 0 && (i != j) && (matCopy[i][k] != 0 && matCopy[k][j] != 0))
                {
                    matCopy[i][j] = matCopy[i][k] + matCopy[k][j];
                }
                else if (((matCopy[k][j] != 0) && (matCopy[i][k] != 0) && (matCopy[i][j] > (matCopy[i][k] + matCopy[k][j]))))
                {
                    matCopy[i][j] = matCopy[i][k] + matCopy[k][j];
                }
            }
        }
    }

    return matCopy[i][j];
}
