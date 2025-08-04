#include <bits/stdc++.h>
using namespace std;

// Summary:

// Floyd-Warshall works on both directed and undirected graphs with positive weights.

// For directed graphs, negative weights are supported as long as there are no negative cycles.

// For undirected graphs, negative weights are not supported, as every negative edge immediately forms a negative cycle, making shortest paths undefined

// helps to detect -ve weight cycle as well, only works in directed graph
// for undirected we need to convert this into directed first
void floydWarshall(vector<vector<int>> &dist)
{
    // Code here
    int n = dist.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                {
                    int newDist = dist[i][k] + dist[k][j];
                    dist[i][j] = min(dist[i][j], newDist);
                }
            }
        }
    }
}

int main()
{

    return 0;
}