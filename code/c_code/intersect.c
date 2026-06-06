#include <stdio.h>

int inersect(int* a, int* b, int size_a, int size_b, int* buff)
{
    int size_max = 0;
    int intersections = 0;

    if(size_a >= size_b)
    {
        size_max = size_a;
    }
    else
    {
        size_max = size_b;
    }

    int arr[size_max];

    for(int i = 0; i < size_b; ++i)
    {
        for(int j = 0; j < size_a; ++j)
        {
            if(a[j] == b[i])
            {
                arr[intersections] = a[j];
                ++intersections;
            }
            else
            {
                continue;
            }
        }
    }

    for(int i = 0; i < intersections; ++i)
    {
        buff[i] = arr[i];
    }

    return intersections;
}

int main()
{
    int arr1[] = {1, 3, 4, 5, 8};
    int arr2[] = {3, 4, 1};

    int size_max;

    if(sizeof(arr1)/sizeof(arr1[0]) >= sizeof(arr2)/sizeof(arr2[0]))
    {
        size_max = sizeof(arr1)/sizeof(arr1[0]);
    }
    else
    {
        size_max = sizeof(arr2)/sizeof(arr2[0]);
    }

    int buff[size_max];

    int inter = inersect(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]), sizeof(arr2)/sizeof(arr2[0]), buff);

    for(int i = 0; i < inter; ++i)
    {
        printf("%d ", buff[i]);
    }

    return 0;
}
