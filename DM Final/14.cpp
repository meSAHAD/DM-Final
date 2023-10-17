#include <stdio.h>
#include <limits.h>

#define V 4

// Function to find the minimum of two integers
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Function to compute the total cost of a path
int computePathCost(int path[], int graph[][V])
{
    int cost = 0;
    for (int i = 0; i < V - 1; i++)
    {
        cost += graph[path[i]][path[i + 1]];
    }
    cost += graph[path[V - 1]][path[0]]; // Return to the starting city
    return cost;
}

// Function to solve the TSP using a naive approach
int travelingSalesmanProblem(int graph[][V], int s)
{
    int vertex[V];
    for (int i = 0; i < V; i++)
    {
        if (i != s)
        {
            vertex[i] = i;
        }
    }

    int minPath = INT_MAX;
    do
    {
        int currentPath[V];
        for (int i = 0; i < V; i++)
        {
            currentPath[i] = vertex[i];
        }
        currentPath[V - 1] = s;

        int pathCost = computePathCost(currentPath, graph);
        minPath = min(minPath, pathCost);
    } while (next_permutation(vertex, vertex + V - 1));

    return minPath;
}

int main()
{
    int graph[V][V] = {{0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};
    int s = 0;
    printf("%d\n", travelingSalesmanProblem(graph, s));
    return 0;
}
