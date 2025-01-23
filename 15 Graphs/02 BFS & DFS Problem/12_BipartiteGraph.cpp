#include <bits/stdc++.h>
using namespace std;

// Approach :
//  1. Bipartite graph : graphs whose every alternate node is either 0 and 1,
//  2. every graph which is linear
//  3. every odd no of cycle is not bi-partite
//  4. Every even no of Cycle is bi-partite
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
                    else
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