#include <bits/stdc++.h>
using namespace std;

bool dfsTraversal(int currNode, vector<int> &visited,vector<int> &path, vector<vector<int>> &adj, stack<int> &st)
{
    visited[currNode] = 1;
    path[currNode] = 1;
    for (int neighbour : adj[currNode])
    {
        if (!visited[neighbour])
        {
            if(dfsTraversal(neighbour, visited, path, adj, st)) return true;
        }
        else if (path[neighbour] == 1){
            return true;
        } 
    }
    path[currNode] = 0;// back to 0 again, 
    st.push(currNode);
    return false;
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    // Your code here
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> path(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if(dfsTraversal(i, visited, path, adj, st)) return {};
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

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    for(int i = 0; i < prerequisites.size(); i ++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjList[v].push_back(u);
    }
    vector<int> result = topologicalSort(adjList);
    return result;
}

int main()
{

    return 0;
}