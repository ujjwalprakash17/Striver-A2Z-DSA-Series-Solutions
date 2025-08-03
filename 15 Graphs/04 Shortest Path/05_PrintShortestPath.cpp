#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    if (m == 0)
        return {-1};
    vector<int> ans;
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }
    set<pair<int, int>> setDS;
    vector<int> dist(n + 1, 1e9);
    setDS.insert({0, 1});
    vector<int> ans;
    while (!setDS.empty())
    {
        auto it = setDS.begin();
        setDS.erase(it);
        int currNode = it->second;
        int currwt = it->first;
        ans.push_back(currNode);
        if(currNode == n) return ans;
        for (auto neighbour : adjList[currNode])
        {
            int neighbourNode = neighbour.first;
            int neighbourWt = neighbour.second;
            int newDist = currwt + neighbourWt;
            if (newDist < dist[neighbourNode])
            {
                if (dist[neighbourNode] != 1e9)
                {
                    setDS.erase({dist[neighbourNode], neighbourNode});
                }
                setDS.insert({newDist, neighbourNode});
                dist[neighbourNode] = newDist;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}