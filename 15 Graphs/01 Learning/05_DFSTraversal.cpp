#include <bits/stdc++.h>
using namespace std;

// dfs : use recursive method to traverse using dfs method : visit depth of each node first then backtrack and visit its neighbour nodes
// whi node ke liye call lagao jo visited nhi hai


void dfsTraversal(int node, vector<int>adj[], vector<int> &visited, vector<int> &dfs)
{
    visited[node] = 1;
    dfs.push_back(node);
    for(auto it: adj[node])
    {
        if(!visited[it])
        dfsTraversal(it, adj, visited, dfs);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> dfs;
    vector<int> visited(V, 0);
    int start = 0;
    dfsTraversal(start, adj, visited, dfs); 
    return dfs;
}
int main()
{

    return 0;
}