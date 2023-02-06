#include <stdio.h>
#include <stdlib.h>
int find(int [],int);		//Declaration of find function
int uni(int [],int, int);		//Declaration of uni function
void main() 
{
    int i, j, k, a, b, u, v, n, ne = 1;
    int min, mincost = 0, cost[9][9], parent[9]={0};
    printf("Implementation of Kruskal's Algorithm\n");
    printf("Enter the no. of vertices:");		//Taking number of vertices
    scanf("%d", & n);
    printf("Enter the cost adjacency matrix:\n");		//Taking cost of nodes
    for (i = 1; i <= n; i++) 
	{
        for (j = 1; j <= n; j++) 
		{
            scanf("%d", & cost[i][j]);
            if (cost[i][j] == 0)
            	cost[i][j] = 999;
        }
    }
    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n) 
	{
    	for (i = 1, min = 999; i <= n; i++) 
		{
            for (j = 1; j <= n; j++) 
			{
            	if (cost[i][j] < min) 
				{
              		min = cost[i][j];
              		a = u = i;
              		b = v = j;
            	}
          	}
        }
        u = find(parent,u);		//Calling find function	
        v = find(parent,v);		//Calling uni function
        if (uni(parent,u, v)) 
		{
          printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
          mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost = %d\n", mincost);		//Printing minimum cost
}
int find(int parent[],int i)		//Defination of find function
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int parent [],int i, int j)		//Defination of uni function
{
    if (i != j) 
	{
        parent[j] = i;
        return 1;
    }
    return 0;
}