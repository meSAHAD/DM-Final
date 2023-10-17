#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a graph edge
struct Edge
{
    int src, dest, weight;
};

// Create a new graph edge
struct Edge *createEdge(int src, int dest, int weight)
{
    struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;
    return edge;
}

// Compare function for sorting edges based on their weights
int compareEdges(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to find the parent of a vertex using union-find (disjoint-set) data structure
int findParent(int parent[], int vertex)
{
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}

// Function to perform union operation in the disjoint-set data structure
void unionSets(int parent[], int x, int y)
{
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[xSet] = ySet;
}

// Function to find the MST using Kruskal's algorithm
void kruskalMST(struct Edge *edges, int numEdges, int numVertices)
{
    // Sort the edges in non-decreasing order of weight
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    // Allocate memory for parent array for union-find
    int *parent = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
        parent[i] = -1;

    struct Edge *mst[numVertices - 1]; // MST will have V-1 edges
    int mstEdgeCount = 0;

    for (int i = 0; i < numEdges && mstEdgeCount < numVertices - 1; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int srcParent = findParent(parent, src);
        int destParent = findParent(parent, dest);

        // Check if including this edge does not create a cycle
        if (srcParent != destParent)
        {
            mst[mstEdgeCount++] = &edges[i];
            unionSets(parent, srcParent, destParent);
        }
    }

    // Print the MST
    printf("Minimum Spanning Tree (Edges and Weights):\n");
    for (int i = 0; i < mstEdgeCount; i++)
    {
        printf("Edge (%d - %d) with weight %d\n", mst[i]->src, mst[i]->dest, mst[i]->weight);
    }

    free(parent);
}

int main()
{
    int numVertices = 4;
    int numEdges = 5;
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
    };

    kruskalMST(edges, numEdges, numVertices);

    return 0;
}
