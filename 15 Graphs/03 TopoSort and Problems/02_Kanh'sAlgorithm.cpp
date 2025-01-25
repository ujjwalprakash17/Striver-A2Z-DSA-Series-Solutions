#include <bits/stdc++.h>
using namespace std;

// Approach

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    // Your code here
    // 1. Count the indegree of each of  the node
    int n = adj.size();
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int val = adj[i][j];
            indegree[val]++;
        }
    }
    // push those into queue whose indegree is 0
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    // iterate and perform dfs based on indegree and store ans 
    vector<int> ans;
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        ans.push_back(currNode);
        for(int neighbour : adj[currNode])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            q.push(neighbour);
        }
    }
    return ans;
}

int main()
{

    return 0;
}