#include <bits/stdc++.h>
using namespace std;

//Approach : 
// 1.our simple approach is to traverse and do the simple bfs Traversal
// 2. and take another variable distance with you 

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n , INT_MAX);
    vector<int> visited(n , 0);
    dist[src] = 0;
    queue<int> q;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int neighbour : adj[curr])
        {
            if(dist[neighbour] == INT_MAX)
            {
                dist[neighbour] = curr+1;
                visited[neighbour] = 1;
            }
        }
    }
    for (int &d : dist) {
        if (d == INT_MAX) d = -1;
    }

    return dist;
}


int main()
{

    return 0;
}