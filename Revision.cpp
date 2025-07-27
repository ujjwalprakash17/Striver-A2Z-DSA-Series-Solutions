#include <bits/stdc++.h>
using namespace std;


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
