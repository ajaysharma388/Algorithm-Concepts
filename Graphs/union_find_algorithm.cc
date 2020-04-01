#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge {
    int src, dest;
    
};

struct Graph {
    int V, E;
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}

int find_parents(int parent[], int i) {
    if(parent[i]==-1)
    return i;
    return find_parents(parent, parent[i]);
}

void Make_Union(int parent[], int x, int y) {
    int x_set = find_parents(parent,x);
    int y_set = find_parents(parent,y);
    parent[x_set] = y_set;
}

int isCycle( struct Graph* graph ) {
    int *parent = (int*) malloc( graph->V * sizeof(int) );
 
    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);
 
    // Iterate through all edges of graph, find subset of both
    // vertices of every edge, if both subsets are same, then 
    // there is cycle in graph.
    for(int i = 0; i < graph->E; ++i) {
        int x = find_parents(parent, graph->edge[i].src);
        int y = find_parents(parent, graph->edge[i].dest);
 
        if (x == y)
            return 1;
 
        Make_Union(parent, x, y);
    }
    return 0;
}

int main() {
    
    /*int V = 3, E = 3;
    struct Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );*/
 
    
    int V = 4, E = 3;
    struct Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 3;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
        
        
    /*int V = 5, E = 5;
    struct Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 2-3
    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;
    
        // add edge 2-4
    graph->edge[3].src = 2;
    graph->edge[3].dest = 4;
    
        // add edge 0-4
    graph->edge[4].src = 0;
    graph->edge[4].dest = 4;
 
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );*/
    return 0;   
}