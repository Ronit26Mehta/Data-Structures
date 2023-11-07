#include <stdio.h>
#define max 10

int adj[max][max], tree[max][max], n;

void readmatrix();
int spanningtree(int src);
void display(int cost);

void main() {
    int source, treecost;
    readmatrix();
    printf("\tRonitSatishMehta 6009230207\n");
    printf("Enter the Source:");
    scanf("%d", &source);
    treecost = spanningtree(source);
    display(treecost);
}

void readmatrix() {
    int i, j;
    printf("\nEnter the number of nodes in the graph:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

int spanningtree(int src) {
    int visited[max], d[max], parent[max];
    int i, j, k, min, u, v, cost;
    
    for (i = 1; i <= n; i++) {
        d[i] = adj[src][i];
        visited[i] = 0;
        parent[i] = src;
    }
    
    visited[src] = 1;
    cost = 0;
    k = 1;
    
    for (i = 1; i < n; i++) {
        min = 9999;
        for (j = 1; j <= n; j++) {
            if (visited[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
                cost += d[u];
            }
        }
        
        visited[u] = 1;
        tree[k][1] = parent[u];
        tree[k][2] = u;
        k++;
        
        for (v = 1; v <= n; v++) {
            if (visited[v] == 0 && adj[u][v] < d[v]) {
                d[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    
    return cost;
}

void display(int cost) {
    int i;
    printf("\nThe Edges of the Minimum Spanning tree are:\n");
    for (i = 1; i < n; i++) {
        printf("%d %d\n", tree[i][1], tree[i][2]);
    }
    printf("The Total cost of the Minimum Spanning Tree is: %d\n", cost);
}
