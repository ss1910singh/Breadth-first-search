
#include <stdio.h>
#define size 10

int n, i, j, vis[size], que[size], front = -1, rear = -1;
int adj[size][size];
void bfs(int v)
{
    front = 0;
    vis[v] = 1;
    que[++rear] = v;

    printf("BFS Traversal: ");

    while (front <= rear)
    {
        int j = que[front++];
        printf("%d ", j);

        for (int i = 1; i <= size; i++)
        {
            if (adj[j][i] && !vis[i])
            {
                vis[i] = 1;
                que[++rear] = i;
            }
        }
    }
}

int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        que[i] = 0;
        vis[i] = 0;
    }
    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);

    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            printf("\nBFS is not possible!!!\n");
            return 0;
        }
    }

    printf("\nVertex Connection:\n");
    for (i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            printf("%d is connected to: ", i);
            for (j = 1; j <= n; j++)
            {
                if (adj[i][j] && vis[j])
                {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
