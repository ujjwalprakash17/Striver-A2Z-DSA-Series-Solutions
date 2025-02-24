#include <bits/stdc++.h>
using namespace std;

// Approach :
//  1. Bipartite graph : graphs whose every alternate node is either 0 and 1,
//  2. every graph which is linear
//  3. every odd length of cycle is not bi-partite
//  4. Every even length  of Cycle is bi-partite

// 1. will use to traverse as how we do in connected component only
// 2. we are using bfs to traverse here


bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int currNode = q.front();
                q.pop();
                for (int neighbour : graph[currNode])
                {
                    if (color[neighbour] != -1)
                    {
                        q.push(neighbour);
                        color[neighbour] = 1 - color[currNode];
                    }
                    else if (color[neighbour] == color[currNode])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


int main()
{

    return 0;
}