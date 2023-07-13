#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Exch(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void QuickSort(int a[], int low, int high)
{
    if (low >= high)
        return;

    int key = low;
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && a[i] <= a[key])
            i++;
        while (a[j] > a[key])
            j--;
        if (i < j)
            Exch(&a[i], &a[j]);
    }

    Exch(&a[j], &a[key]);
    QuickSort(a, low, j - 1);
    QuickSort(a, j + 1, high);
}

int main()
{
    int n, a[1000], k;
    clock_t st, et;
    double ts;

    printf("\n Enter how many numbers: ");
    scanf("%d", &n);

    printf("\nThe random numbers are:\n");
    srand(time(NULL));
    for (k = 1; k <= n; k++)
    {
        a[k] = rand();
        printf("%d\t", a[k]);
    }

    st = clock();
    QuickSort(a, 1, n);
    et = clock();

    printf("\nSorted numbers are:\n");
    for (k = 1; k <= n; k++)
        printf("%d\t", a[k]);

    ts = (double)(et - st) / CLOCKS_PER_SEC;
    printf("\nThe time taken is %f seconds\n", ts);

    return 0;
}
