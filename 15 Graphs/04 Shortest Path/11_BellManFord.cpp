#include <bits/stdc++.h>
using namespace std;

// Approach :
//  we need to relax the edges for n - 1 times using a nested for loop only
//  to check for negative weight cycle we need to check that whether these nodes
//  can be furthur minimized if yes, then there is a negative weight cycle
// Bellman-Ford only reliably works on directed graphs when negative weights are present. 
// For undirected graphs, Bellman-Ford is only practical if all edge weights are non-negative

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto &edge : edges)
        {
            int startNode = edge[0];
            int endNode = edge[1];
            int weight = edge[2];
            // we need to add a check if startNode is not equal to 1e8 because this will check for every value of 1e8.
            if (dist[startNode] != 1e8 && dist[startNode] + weight < dist[endNode])
            {
                dist[endNode] = dist[startNode] + weight;
            }
        }
    }

    for (auto &edge : edges)
    {
        int startNode = edge[0];
        int endNode = edge[1];
        int weight = edge[2];
        // also we need to make sure that the visited nodes should only be updated
        if (dist[startNode] != 1e8 && dist[startNode] + weight < dist[endNode])
        {
            return vector<int>(1, -1); // Negative weight cycle found
        }
    }

    return dist;
}

int main()
{

    return 0;
}
