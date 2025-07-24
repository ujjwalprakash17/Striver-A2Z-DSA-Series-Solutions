#include <bits/stdc++.h>
using namespace std;

// 1. will use to traverse as how we do in connected component only
// 2. we are using bfs to traverse here


int main()
{

    return 0;
}

// flood fill

// vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
// {
//     int startingColor = image[sr][sc];
//     queue<pair<int, int>> q;
//     int n = image.size();
//     int m = image[0].size();
//     vector<vector<int>> visited(n, vector<int>(m , 0));
//     q.push({sr, sc});
//     image[sr][sc] = color;
//     while(!q.empty())
//     {
//         int currRow = q.front().first;
//         int currCol = q.front().second;
//         q.pop();
//         int delRow[] = {-1, 0, 1, 0};
//         int delCol[] = {0, 1, 0, -1};
//         for(int i = 0 ; i < 4; i++)
//         {
//             int nRow = currRow + delRow[i];
//             int nCol = currCol + delCol[i];
//             if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == startingColor && !visited[nRow][nCol]){
//                 q.push({nRow,nCol});
//                 image[nRow][nCol] = color;
//                 visited[nRow][nCol] = 1;
//             }

//         }
//     }
//     return image;
// }

// cycle detection in graph using bfs
//  bool checkCycleUsingBFS(int start, vector<int> &visited, vector<vector<int>> &adjList)
//  {
//      int n = adjList.size();
//      vector<int> parent(n, -1);
//      visited[start] = 1;
//      parent[start] = -1;
//      queue<int> q;
//      q.push(start);
//      while (!q.empty())
//      {
//          int curr = q.front();
//          q.pop();
//          for (int neighbour : adjList[curr])
//          {
//              if (!visited[neighbour])
//              {
//                  q.push(neighbour);
//                  visited[neighbour] = 1;
//                  parent[neighbour] = curr;
//              }
//              else if (parent[curr] != neighbour)
//                  return true;
//          }
//      }
//      return false;
//  }

// // using bfs method
// bool isCycle(int V, vector<vector<int>> &edges)
// {
//     // convert the edges into adjList first
//     vector<vector<int>> adjList(V);
//     for (int i = 0; i < edges.size(); i++)
//     {
//         adjList[edges[i][0]].push_back(edges[i][1]);
//         adjList[edges[i][1]].push_back(edges[i][0]);
//     }
//     // consider that nodes can be in different components
//     vector<int> visited(V, 0);
//     for (int i = 0; i < V; i++)
//     {
//         if (!visited[i])
//         {
//             bool cyclePresent = checkCycleUsingBFS(i, visited, adjList);
//             if (cyclePresent == true)
//                 return true;
//         }
//     }
//     return false;
// }

// cycle detection in graph in directed one using dfsTraversal
//  bool dfsTraversal(int start, vector<int> &visited, vector<int> &parent,  vector<vector<int>> &adjList)
//  {
//      visited[start] = 1;
//      for(int neighbour : adjList[start])
//      {
//          if(!visited[neighbour])
//          {
//              parent[neighbour] = start;
//              bool val = dfsTraversal(neighbour, visited, parent, adjList);
//              if(val) return true;
//          }else if(parent[start] != neighbour){
//              return true;
//          }
//      }
//      return false;
//  }

// bool isCycle(int V, vector<vector<int>> &edges)
// {
//     // convert the edges into adjList first
//     vector<int> visited(V, 0);
//     vector<int> parent(V, -1);
//     vector<vector<int>> adjList(V);
//     for(int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
//     for(int i = 0; i < V ; i++)
//     {
//         if(!visited[i]){
//             bool val = dfsTraversal(i, visited, parent, adjList);
//             if(val) return val;
//         }
//     }
//     return false;
// }
















//check if graph is bipartite or not 
// bool bfsTraversal(int i, vector<int> &color ,vector<vector<int>> &graph)
// {
//     queue<int> q;
//     q.push(i);
//     color[i] = 0;
//     while (!q.empty())
//     {
//         int currNode = q.front();
//         q.pop();
//         for (int neighbour : graph[currNode])
//         {
//             if (color[neighbour] == -1)
//             {
//                 q.push(neighbour);
//                 color[neighbour] = 1 - color[currNode];
//             }
//             else if (color[neighbour] == color[currNode])
//             {
//                 return false;
//             }
//         }
//     }
// }

// bool isBipartite(vector<vector<int>> &graph)
// {
//     int n = graph.size();
//     vector<int> color(n, -1);
//     for (int i = 0; i < n; i++)
//     {
//         if (color[i] == -1)
//         {
//             bool val = bfsTraversal(i, color, graph);
//             if(!val) return !val;
//         }
//     }
//     return true;
// }
