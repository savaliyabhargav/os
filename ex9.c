#include <stdio.h>

int m, n, i, j, al[10][10], max[10][10], av[10], need[10][10], temp, z, y, p, k;

void main() {
    printf("\n Enter no of processes : ");
    scanf("%d", &m);

    printf("\n Enter no of resources : ");
    scanf("%d", &n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\n Enter instances for al[%d][%d] = ", i,j);
            scanf("%d", &al[i][j]);
        }
    }
    for (i = 0; i < m;i++) {
        for (j = 0; j < n; j++) {
            printf("\n Enter instances for max[%d][%d] = ", i,j);
            scanf("%d", &max[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        printf("\n Available Resource for av[%d] = ",i);
        scanf("%d", &av[i]);
    }
    printf("Alocation Values :\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf(" \t %d", al[i][j]);
        }
        printf("\n");
    }
    printf("Max Values :\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf(" \t %d", max[i][j]);
        }
        printf("\n");
    }
    printf("Need Values :\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            need[i][j] = max[i][j] - al[i][j];
            printf("\t %d", need[i][j]);
        }
        printf("\n");
    }
    p = 1;
    y = 0;
    while (p != 0) {
        for (i = 0; i < m; i++) {
            z = 0;
            for (j = 0; j < n; j++) {
                if (need[i][j] <= av[j] && (need[i][0] != -1)) {
                    z++;
                }
            }
            if (z == n) {
                for (k = 0; k < n; k++) {
                    av[k] += al[i][k];
                }
                printf("\n SS process %d", i);
                need[i][0] = -1;
                y++;
            }
        }
        if (y == m) {
            p = 0;
        }
    }


}
