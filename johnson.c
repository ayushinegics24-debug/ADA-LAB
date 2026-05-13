#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void print(int p[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}

int mobile(int p[], int dir[], int n)
{
    int m = 0;

    for(int i = 0; i < n; i++)
    {
        int next = i + dir[i];

        if(next >= 0 && next < n &&
           p[i] > p[next] &&
           p[i] > m)
        {
            m = p[i];
        }
    }
    return m;
}

void johnsonTrotter(int n)
{
    int p[n], dir[n];

    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        dir[i] = LEFT;
    }

    int fact = 1;
    for(int i = 2; i <= n; i++)
        fact *= i;

    for(int count = 0; count < fact; count++)
    {
        print(p, n);

        int m = mobile(p, dir, n);
        if(m == 0) break;

        int pos;

        for(pos = 0; pos < n; pos++)
            if(p[pos] == m)
                break;

        int swapPos = pos + dir[pos];


        int temp = p[pos];
        p[pos] = p[swapPos];
        p[swapPos] = temp;

        temp = dir[pos];
        dir[pos] = dir[swapPos];
        dir[swapPos] = temp;

        for(int i = 0; i < n; i++)
            if(p[i] > m)
                dir[i] = -dir[i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
