#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int start, vector<int> &visited, vector<int> &isSafe, vector<vector<int>> &adjList)
{
    visited[start] = 1;
    bool check = true;
    for (int neighbour : adjList[start])
    {
        if (!visited[neighbour])
        {
            dfsTraversal(neighbour, visited, isSafe, adjList);
        }
        if (!isSafe[neighbour])
            check = false;
    }
    isSafe[start] = check;
}

vector<int> eventualSafeNodes(vector<vector<int>> &adjList)
{
    int n = adjList.size();
    vector<int> visited(n, 0);
    vector<int> isSafe(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsTraversal(i, visited, isSafe, adjList);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (isSafe[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{

    return 0;
}