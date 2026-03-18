#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10000], temp[10000], n;

void merge(int low, int mid, int high)
{
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergesort(int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{
    int i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    for(i = 0; i < n; i++)
        a[i] = rand() % 1000;
    start = clock();

   for(int i=0;i<100;i++)
    mergesort(0,n-1);

    end = clock();

    printf("\nSorted elements:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}
