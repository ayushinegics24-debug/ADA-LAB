#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int i, j, min, u = 0, v = 0, total = 0, ne = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST (Prim's):\n");

    while(ne < n) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", u, v, min);
        total += min;
        visited[v] = 1;
        ne++;
    }

    printf("Total cost = %d\n", total);

    return 0;
}
