#include <bits/stdc++.h>
using namespace std;

//Approach : 
// 1.our simple approach is to traverse and do the simple bfs Traversal
// 2. and take another variable distance with you 


vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    // code here
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> ans(n, INT_MAX);
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = 1;
    while (!q.empty())
    {
        int currNode = q.front().first;
        int currDist = q.front().second;
        q.pop();
        ans[currNode] = min(ans[currNode], currDist);
        for (int neighbour : adj[currNode])
        {
            if (!visited[neighbour])
            {
                q.push({neighbour, currDist + 1});
                visited[neighbour] = 1;
            }
        }
    }
    //those who are not yet visited, means they can't be reached through the source so will mark -1
    for(int i = 0; i < n ; i++)
    {
        if(visited[i] == 0)
        ans[i] = -1;
    }
    return ans;
}

int main()
{

    return 0;
}