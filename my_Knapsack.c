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
    sum = mat[ITEMS][WEIGHT];

    for (i = ITEMS; i > 0 && sum > 0; i--)
    {
        inSum = (sum != mat[i - 1][currWeight]);

        if(inSum)
        {
            selected_bool[i - 1] = 1;
            sum -= values[i - 1];
            currWeight -= weights[i - 1];
        }

    }

    return mat[ITEMS][WEIGHT];
}

/*
Function will perform the fgets command and also remove the newline
that might be at the end of the string - a known issue with fgets.
input: size (int) - number of chars to read
       str (char*) - string to read into
output: none
*/
void myFgets(int size, char* str)
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}

int main(int argc, char* argv[])
{
    int i = 0;
    char items[ITEMS][WEIGHT] = {0};
    int result[ITEMS] = {0};
    int itemWeights[ITEMS] = {0};
    int itemValues[ITEMS] = {0};

    for (i = 0; i < ITEMS - 1; i++)
    {
        myFgets(WEIGHT, items[i]);
        scanf("%d", &itemValues[i]);
        scanf("%d ", &itemWeights[i]);
    }

    myFgets(WEIGHT, items[ITEMS - 1]);
    scanf("%d", &itemValues[ITEMS - 1]);
    scanf("%d", &itemWeights[ITEMS - 1]);
    
    
    printf("Maximum profit: %d\n", knapSack(itemWeights,itemValues,result));
    printf("Selected items:");
    for (i = 0; i < ITEMS; i++)
    {
        if(result[i]) {printf(" %s", items[i]);}
    }

    return 0;
}