#include<stdio.h>
#define V 4
#define E 5

void init(int graph[V][E])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<E;j++)
            graph[i][j] = 0;
    }
}

void addedge(int graph[V][E],int e,int o,int i,int weight)
{
    graph[i][e] = 0 - weight;
    graph[o][e] = weight;
}

void print(int graph[V][E])
{

    printf("\t");

    for(int i=0;i<E;i++)
        printf("%d\t",i);
    printf("\n");
    for(int i=0;i<V;i++)
    {
        printf("%d:\t",i);
        for(int j=0;j<E;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
}

main()
{
    int graph[V][E];

    init(graph);

    addedge(graph,0,0,1,48);

    addedge(graph,1,3,1,54);
    addedge(graph,2,0,2,41);
    addedge(graph,3,3,2,21);
    addedge(graph,4,0,3,31);

    print(graph);
}
