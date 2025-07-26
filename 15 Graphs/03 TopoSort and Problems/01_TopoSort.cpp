#include <bits/stdc++.h>
using namespace std;
// we are performing topological Sort using dfs

void dfsTraversal(int currNode, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
{
    visited[currNode] = 1;
    for (int neighbour : adj[currNode])
    {
        if (!visited[neighbour])
        {
            dfsTraversal(neighbour, visited, adj, st);
        }
    }
    st.push(currNode);
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    // Your code here
    int n = adj.size();
    vector<int> visited(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsTraversal(i, visited, adj, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        int node = st.top();
        ans.push_back(node);
        st.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> adj = {
        {},
        {3},
        {3},
        {},
        {0, 1},
        {0, 2}
    };
    topologicalSort(adj);

    return 0;
}



void dfsTraversal(int start, stack<int> &s, vector<int> &visited, vector<vector<int>> &adjList)
{
    visited[start] = 1;
    for (int neighbour : adjList[start])
    {
        if (!visited[neighbour])
        {
            dfsTraversal(neighbour, s, visited, adjList);
        }
    }
    s.push(start); // we need to visit its neighbour first
}
//Revision time code 

// vector<int> topoSort(int V, vector<vector<int>> &edges)
// {
//     // code here
//     vector<vector<int>> adjList(V);
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adjList[u].push_back(v);
//     }

//     stack<int> s;
//     vector<int> visited(V, 0);
//     for (int i = 0; i < V; i++)
//     {
//         if (!visited[i])
//         {
//             dfsTraversal(i, s, visited, adjList);
//         }
//     }
//     for (int i = 0; i < adjList.size(); i++)
//     {
//         for (int ele : adjList[i])
//         {
//             cout << ele << " ";
//         }
//         cout << "\n";
//     }
//     vector<int> topoSort;
//     while (!s.empty())
//     {
//         int curr = s.top();
//         topoSort.push_back(curr);
//         s.pop();
//     }
//     return topoSort;
// }
