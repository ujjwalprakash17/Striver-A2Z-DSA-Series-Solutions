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
    // reverse
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}