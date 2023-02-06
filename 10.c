#include<stdio.h>
void DFS(int G[10][10],int visited[10],int n,int);    //Declaration of DFS
void main()
{
    int G[10][10], visited[10], n, i, j;
    printf("Enter number of vertices:");    //Taking number of vertices
    scanf("%d",&n);
    printf("Enter adjacency matrix of the graph:\n");
    for(i=0;i<n;i++)    //Taking adjacency matrix
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    for(i=0;i<n;i++)
        visited[i]=0;
    DFS(G,visited,n,0);   //Calling DFS
}
void DFS(int G[10][10],int visited[10],int n,int i)   //Defination of DFS
{
    int j;
    printf("\n%d",i);   //Print path
    visited[i]=1;
    for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
            DFS(G,visited,n,j);   //Recurrsion of DFS
}