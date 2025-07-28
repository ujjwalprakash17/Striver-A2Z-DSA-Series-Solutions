#include <bits/stdc++.h>
using namespace std;

bool dfsTraversal(int start, vector<int> &visited, vector<int>& recStack, vector<vector<int>> &adjList)
{
    visited[start] = 1;
    recStack[start] = 1;
    for (int neighbour : adjList[start]) {
        if (!visited[neighbour]) {
            if (dfsTraversal(neighbour, visited, recStack, adjList)) {
                return true;  // Cycle found in deeper recursion
            }
        } else if (recStack[neighbour]) {
            // Back edge found - neighbour is in current recursion path
            return true;  // CYCLE DETECTED
        }
    }
    
    recStack[start] = 0;  
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    // convert this into an adjList
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjList[u].push_back(v);
    }
    vector<int> visited(numCourses, 0);
    vector<int> recStack(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            bool val = dfsTraversal(i, visited, recStack, adjList);
            if (val == true)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}

// vector<int> topoSort(int V, vector<vector<int>> &edges)
// {
//     // code here
//     vector<vector<int>> adjList(V);
//     // create a adjList first
//     vector<int> indegree(V, 0);
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         indegree[v]++;
//         adjList[u].push_back(v);
//     }
//     queue<int> q;
//     for (int i = 0; i < V; i++)
//     {
//         if (indegree[i] == 0)
//         {
//             q.push(i);
//         }
//     }
//     vector<int> topoArr;
//     while (!q.empty())
//     {
//         int curr = q.front();
//         topoArr.push_back(curr);
//         q.pop();
//         for (int neighbour : adjList[curr])
//         {
//             indegree[neighbour]--;
//             if (indegree[neighbour] == 0)
//             {
//                 q.push(neighbour);
//             }
//         }
//     }

//     return topoArr;
// }

// void dfsTraversal(int start, vector<int> &visited, stack<int> &s, vector<vector<int>> &adjList)
// {
//     visited[start] = 1;
//     for(int neighbour : adjList[start])
//     {
//         if(!visited[neighbour])
//         {
//             dfsTraversal(neighbour, visited, s, adjList);
//         }
//     }
//     s.push(start);
// }

// bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
// {
//     vector<vector<int>> adjList(numCourses);

//     for (int i = 0; i < prerequisites.size(); i++)
//     {
//         int u = prerequisites[i][0];
//         int v = prerequisites[i][1];
//         adjList[u].push_back(v);
//     }
//     stack<int> st;
//     vector<int> visited(numCourses, 0);
//     for (int i = 0; i < numCourses; i++)
//     {
//         if (!visited[i])
//         {
//             dfsTraversal(i, visited, s, adjList);
//         }
//     }
//     if (st.size() == numCourses)
//         return true;
//     return false;
// }
