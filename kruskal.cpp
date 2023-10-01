//Performing Kruskal's Algorithm to find the maximum spanning tree using file handling
#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void KruskalMST(struct Graph* graph, FILE* output) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {

            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    fprintf(output, "Minimum Spanning Tree in adjacency list format:\n");
    for (i = 0; i < e; ++i) {
        fprintf(output, "%d: (%d,%d)\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
    }

    free(subsets);
}

int main(void) {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        printf("Enter edge %d (src dest weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        graph->edge[i].src = src - 1; 
        graph->edge[i].dest = dest - 1;
        graph->edge[i].weight = weight;
    }

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        free(graph->edge);
        free(graph);
        return 1;
    }

    KruskalMST(graph, outputFile);

    fclose(outputFile);

    free(graph->edge);
    free(graph);

    return 0;
}
