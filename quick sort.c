#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10000], n;

int partition(int low, int high)
{
    int pivot, i, j, temp;

    pivot = a[low];
    i = low + 1;
    j = high;

    while(1)
    {
        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
        {

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
            break;
    }


    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int low, int high)
{
    if(low < high)
    {
        int pi;

        pi = partition(low, high);

        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
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

for(int k = 0; k < 100; k++)
{
    quicksort(0, n - 1);
}

end = clock();
    printf("\nSorted elements:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}
