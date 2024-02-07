#include <stdio.h>

#define ITEMS 5
#define WEIGHT 20

int max(int a, int b){ return (a > b) ? a : b;}

int knapSack(int weights[], int values[] , int selected_bool[])
{
    int i = 0, sum = 0, currItem = 0,currWeight = 0, itemVal = 0, itemWeight = 0, inSum = 0;
    int mat[ITEMS + 1][WEIGHT + 1] ={{0}};

    for (currItem = 1; currItem < ITEMS + 1; currItem++)
    {
        itemVal = values[currItem - 1];
        itemWeight = weights[currItem - 1];

        for (currWeight = 1; currWeight < WEIGHT + 1; currWeight++)
        {
            if (itemWeight > currWeight)
            {
                mat[currItem][currWeight] = mat[currItem - 1][currWeight];
            }
            else
            {
                mat[currItem][currWeight] = max(mat[currItem - 1][currWeight], mat[currItem - 1][currWeight - itemWeight] + itemVal);
            }
        }
    }

    currWeight = WEIGHT;

    for (i = ITEMS; i > 0; i--)
    {
        inSum = (mat[i][currWeight] != mat[i - 1][currWeight]);

        if(inSum || currWeight >= 0)
        {
            selected_bool[i - 1] = 1;
            sum += values[i - 1];
            currWeight -= weights[i - 1];
        }

    }

    return mat[ITEMS][WEIGHT];
}

int main(int argc, char* argv[])
{
    int indexer = 0;
    int result[ITEMS] = {0};
    int itemWeights[ITEMS] = {0};
    int itemValues[ITEMS] = {0};

    do
    {
        indexer = (int)(getchar()- 'a');
        scanf("%d", &itemValues[indexer]);
        scanf("%d ", &itemWeights[indexer]);
    } while (indexer < ITEMS - 1);

    indexer = (int)(getchar()- 'a');
    scanf("%d", &itemValues[indexer]);
    scanf("%d", &itemWeights[indexer]);
    
    
    printf("Maximum profit: %d\n", knapSack(itemWeights,itemValues,result));
    printf("Selected Items:");
    for (indexer = 0; indexer < ITEMS; indexer++)
    {
        if(result[indexer]) {printf(" %c", (char)(indexer + 'a'));}
    }

    return 0;
}