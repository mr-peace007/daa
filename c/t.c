#include <stdio.h>

int s, c[100][100], ver;
float optimum = 999, sum;

void swap(int v[], int i, int j)
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void tsp(int v[], int n, int i)
{
    int j, sum1, k;
    if (i == n)
    {
        if (v[0] == s)
        {
            for (j = 0; j < n; j++)
                sum1 = 0;
            for (k = 0; k < n - 1; k++)
            {
                sum1 = sum1 + c[v[k]][v[k + 1]];
            }
            sum1 = sum1 + c[v[n - 1]][s];
            if (sum1 < optimum)
                optimum = sum1;
        }
    }
    else
    {
        for (j = i; j < n; j++)
        {
            swap(v, i, j);
            tsp(v, n, i + 1);
            swap(v, i, j);
        }
    }
}

void approx(int ver)
{
    int min, p, i, j, vis[20], from;
    for (i = 1; i <= ver; i++)
        vis[i] = 0;
    vis[s] = 1;
    from = s;
    sum = 0;
    for (j = 1; j < ver; j++)
    {
        min = 999;
        for (i = 1; i <= ver; i++)
        {
            if (vis[i] != 1 && c[from][i] < min && c[from][i] != 0)
            {
                min = c[from][i];
                p = i;
            }
        }
        vis[p] = 1;
        from = p;
        sum = sum + min;
    }
    sum = sum + c[from][s];
}

int main()
{
    int v[100], i, j;
    printf("Enter n: ");
    scanf("%d", &ver);
    for (i = 0; i < ver; i++)
        v[i] = i + 1;
    printf("Enter cost matrix (999 for infinity):\n");
    for (i = 1; i <= ver; i++)
        for (j = 1; j <= ver; j++)
            scanf("%d", &c[i][j]);
    printf("\nEnter source: ");
    scanf("%d", &s);
    tsp(v, ver, 0);
    printf("\nOptimum solution is = %.2f\n", optimum);
    approx(ver);
    printf("\nSolution with Approximation Algorithm is = %.2f\n", sum);
    printf("\nThe approximation value is = %.2f%%\n", ((sum / optimum) - 1) * 100);

    return 0;
}
