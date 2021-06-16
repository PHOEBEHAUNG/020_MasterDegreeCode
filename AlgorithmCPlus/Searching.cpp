/// Linear 
/// Binary
/// Interpolation
/// Hash table 

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
        printf("x[%d] = %d\n", i, x);
        targetArr[i] = x;
    }
}

void LinearSearching(const int* test, int target, int* pos, int size)
{
    int i = 0;
    bool found = false;

    for(i = 0; i < size; i++)
    {
        if(test[i] == target)
        {
            memcpy(pos, &i, sizeof(int));
            found = true;
            break;
        }
    }

    if(!found)
    {
        memcpy(pos, 0, sizeof(int));
    }
}

void BinarySearching(const int* test, int target, int* pos, int size)
{

}

void InterpolationSearching(const int* test, int target, int* pos, int size)
{

}

void HashTableSearching(const int* test, int target, int* pos, int size)
{
    
}

int main(void)
{
    constexpr size_t size = 20;
    int testNumbers[size] {0};
    int answer;
    int target = 5;

    GenRandomArray(10, 0, testNumbers, size);
    
    printf("===================LinearSearching===================\n");
    LinearSearching(testNumbers, target, &answer, size);
    printf("LinearSearching = %d\n", answer);
    
    return 0;
}