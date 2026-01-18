#include <stdio.h>

int n, adj[10][10], visited[10];

/* -------- DFS -------- */
void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
}

/* -------- BFS -------- */
void bfs(int start)
{
    int q[10], front = 0, rear = -1;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    q[++rear] = start;

    while (front <= rear)
    {
        int v = q[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
    }
}

int main()
{
    int start, choice;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting city: ");
    scanf("%d", &start);

    printf("1. BFS\n2. DFS\nEnter choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    if (choice == 1)
    {
        printf("BFS traversal: ");
        bfs(start);
    }
    else if (choice == 2)
    {
        printf("DFS traversal: ");
        dfs(start);
    }
    else
        printf("Invalid choice");

    return 0;
}
