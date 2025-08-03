#include <bits/stdc++.h>
using namespace std;



vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<vector<pair<int, int>>> adjList(V);
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }   
    set<pair<int, int>> setSpace;
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    setSpace.insert({0, src});
    while(!setSpace.empty())
    {
        auto topEle = setSpace.begin();
        setSpace.erase(setSpace.begin());
        int currWt = topEle->first;
        int currNode = topEle->second;
        for(auto neighbour : adjList[currNode]){
            int neighbourNode = neighbour.first;
            int neighbourWt = neighbour.second;
            int newDist = currWt + neighbourWt;
            if(newDist < dist[neighbourNode])
            {
                if(dist[neighbourNode] != 1e9){
                    setSpace.erase({dist[neighbourNode], neighbourNode});
                }
                setSpace.insert({newDist, neighbourNode});
                dist[neighbourNode] = newDist;
            }
        }
    }
    return dist;
}


int main()
{

    return 0;
}