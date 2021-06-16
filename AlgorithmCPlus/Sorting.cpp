#include <iostream>
#include <cstring>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */

void GenRandomArray(int max, int min, int* targetArr, int size)
{
    int x = 0;

    /* 設定亂數種子 */
    srand( time(NULL) ); 
    for (int i = 0; i < size; i++)
    {
        x = (max - min) * rand() / (RAND_MAX + 1) + min;
        printf("x = %d\n", x);
        targetArr[i] = x;
    }
}

void BubbleSorting(const int* test, int* result, int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    memcpy(result, test, size * sizeof(int));

    /// 控制比較幾ROUND
    for(i = 0; i < size; i++)
    {
        /// 控制每一ROUND的比較
        for(j = 1; j < size; j++)
        {
            if(result[j - 1] > result[j])
            {
                temp = result[j - 1];
                result[j - 1] = result[j];
                result[j] = temp;
            }
        }
    }
}

void InsertSorting(const int* test, int* result, int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    memcpy(result, test, size * sizeof(int));

    int keep = 0;
    for(i = 1; i < size; i++)
    {   
        //printf("===================InsertSorting===================\n");
        keep = result[i];
        //printf("[%d] = %d\n", i, keep);
        for(j = i - 1; j >= 0; j--)
        {
            if(keep < result[j])
            {
                temp = result[j + 1];
                result[j + 1] = result[j];
                result[j] = temp;
            }
            else
            {   
                break;
            }
        }

        // for(int k = 0; k < size; k++)
        // {
        //     printf("[%d] = %d, ", k, result[k]);
        //     printf("\n");
        // }
    }

}

void SelectionSorting(const int* test, int* result, int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    memcpy(result, test, size * sizeof(int));

    int minIndex = 0;
    for(i = 0; i < size; i++)
    {   
        minIndex = i;
        for(j = i; j < size; j++)
        {
            /// find the minimun
            if(result[j] < result[minIndex])
            {
                minIndex = j;
            }
        }

        temp = result[minIndex];
        result[minIndex] = result[i];
        result[i] = temp;
    }
}

void QuickSorting(const int* test, int* result, int size)
{
    memcpy(result, test, size * sizeof(int));
}

void MergeSorting(const int* test, int* result, int size)
{
    memcpy(result, test, size * sizeof(int));
}

void ShellSorting(const int* test, int* result, int size)
{
    memcpy(result, test, size * sizeof(int));
}

void HeapSorting(const int* test, int* result, int size)
{
    memcpy(result, test, size * sizeof(int));
}

int main(void)
{
    constexpr size_t size = 20;
    int testNumbers[size] {0};
    int resNumbers[size] {0};

    GenRandomArray(100, 0, testNumbers, size);
    
    printf("===================BubbleSorting===================\n");
    BubbleSorting(testNumbers, resNumbers, size);
    for (int i = 0; i < size; i++)
    {
        printf("resNumbers = %d\n", resNumbers[i]);
    }

    printf("===================InsertSorting===================\n");
    InsertSorting(testNumbers, resNumbers, size);
    for (int i = 0; i < size; i++)
    {
        printf("resNumbers = %d\n", resNumbers[i]);
    }

    printf("===================SelectionSorting===================\n");
    SelectionSorting(testNumbers, resNumbers, size);
    for (int i = 0; i < size; i++)
    {
        printf("resNumbers = %d\n", resNumbers[i]);
    }
    return 0;
}