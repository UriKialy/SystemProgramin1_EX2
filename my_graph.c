#include "my_mat.h"

int main(int argc, char *argv[])
{
    int len = 0;
    char selection = 0, i = 0, j = 0;
    int mat[MAT_SIZE][MAT_SIZE] = {{0}};

    selection = getchar();

    switch (selection)
    {
    case 'A':
        initMatrix(mat);
        break;
    case 'B':
        i = getchar();
        j = getchar();

        floydWarshallAlgorithm(mat, i, j) ? printf("True\n") : printf("False\n");
        break;
    case 'C':
        i = getchar();
        j = getchar();

        len = floydWarshallAlgorithm(mat, i, j) ? printf("%d\n", len) : printf("-1\n");
        break;
    case 'D':
    case EOF:
        break;

    default:
        break;
    }
    
    return 0;
}