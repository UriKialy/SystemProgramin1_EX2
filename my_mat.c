#include "my_mat.h"

void initMatrix(int mat[][MAT_SIZE])
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            scanf("%d", mat[i][j]);
        }
    }
}
