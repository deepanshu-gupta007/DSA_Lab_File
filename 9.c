#include <stdio.h>
#include <stdlib.h>
struct AdjListNode     //Structure of adjacent list node
{
    int dest;
    struct AdjListNode* next;
};
struct AdjList     //Structure of adjacent list
{
    struct AdjListNode* head;
};
struct Graph     //Structure of graph
{
    int V;
    struct AdjList* array;
};
struct AdjListNode* newAdjListNode(int);        //Declaration of creating adjacent list node
struct Graph* createGraph(int);        //Declaration of creating graph
void addEdge(struct Graph*, int, int);        //Declaration of edges function
void printGraph(struct Graph*);        //Declaration to display function

int main()
{
    int V=5;
    struct Graph* graph=createGraph(V);
    addEdge(graph, 0, 1);       //Calling egde function with parameters
    addEdge(graph, 0, 4);       //Calling egde function with parameters
    addEdge(graph, 1, 2);       //Calling egde function with parameters
    addEdge(graph, 1, 3);       //Calling egde function with parameters
    addEdge(graph, 1, 4);       //Calling egde function with parameters
    addEdge(graph, 2, 3);       //Calling egde function with parameters
    addEdge(graph, 3, 4);       //Calling egde function with parameters
    printGraph(graph);      //Calling display function
    return 0;
}
struct AdjListNode* newAdjListNode(int dest)        //Defination of creating adjacent list node
{
    struct AdjListNode* newNode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}
struct Graph* createGraph(int V)        //Defination of creating graph
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->array=(struct AdjList*)malloc(V*sizeof(struct AdjList));
    int i;
    for (i=0; i<V; ++i)
        graph->array[i].head = NULL;
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest)        //Defination of edges function
{
    struct AdjListNode* check=NULL;
    struct AdjListNode* newNode=newAdjListNode(dest);
    if (graph->array[src].head==NULL) 
    {
        newNode->next=graph->array[src].head;
        graph->array[src].head=newNode;
    }
    else 
    {
        check=graph->array[src].head;
        while (check->next != NULL) 
            check=check->next;
        check->next=newNode;
    }
    newNode=newAdjListNode(src);
    if (graph->array[dest].head==NULL) 
    {
        newNode->next=graph->array[dest].head;
        graph->array[dest].head=newNode;
    }
    else 
    {
        check=graph->array[dest].head;
        while (check->next!=NULL)
            check=check->next;
        check->next=newNode;
    }
}
void printGraph(struct Graph* graph)        //Defination to display function
{
    int v;
    for (v=0; v<graph->V; ++v) 
    {
        struct AdjListNode *p=graph->array[v].head;
        printf("Adjacency list of vertex %d\n head ", v);
        while (p) 
        {
            printf("-> %d", p->dest);
            p=p->next;
        }
        printf("\n");
    }
}
