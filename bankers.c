#include<stdio.h>

int main()
{
    // P0, P1, P2, P3, P4 are process names

    int n, m, i, j, k;

    n = 5; // Number of processes
    m = 3; // Number of resource types

    // Allocation Matrix
    int alloc[5][3] =
    {
        {0, 1, 0}, // P0
        {2, 0, 0}, // P1
        {3, 0, 2}, // P2
        {2, 1, 1}, // P3
        {0, 0, 2}  // P4
    };

    // Maximum Matrix
    int max[5][3] =
    {
        {7, 5, 3}, // P0
        {3, 2, 2}, // P1
        {9, 0, 2}, // P2
        {2, 2, 2}, // P3
        {4, 3, 3}  // P4
    };

    // Available Resources
    int avail[3] = {3, 3, 2};

    int f[n], ans[n], ind = 0;

    // Initialize finish array
    for(k = 0; k < n; k++)
    {
        f[k] = 0;
    }

    // Need Matrix
    int need[n][m];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's Algorithm
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            if(f[i] == 0)
            {
                int flag = 0;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0)
                {
                    ans[ind++] = i;

                    for(j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for(i = 0; i < n; i++)
    {
        if(f[i] == 0)
        {
            flag = 0;
            printf("System is NOT in safe state\n");
            break;
        }
    }

    if(flag == 1)
    {
        printf("System is in SAFE state\n");
        printf("Safe Sequence is:\n");

        for(i = 0; i < n - 1; i++)
        {
            printf("P%d -> ", ans[i]);
        }

        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}