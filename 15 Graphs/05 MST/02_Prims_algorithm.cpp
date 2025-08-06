#include <bits/stdc++.h>
using namespace std;
// MST : A Graph whose sum of edge weights are minimum, where no of nodes are n & no of edges are n -1, and each node is connected to each other
// this is called as MST

int spanningTree(int V, vector<vector<int>> &edges)
{
    // code here
    // create an convert into an adjList
    vector<vector<pair<int, int>>> adjList(V);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }
    // Algorithm for prims
    //  1.Store into
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<int> visited(V, 0);
    vector<pair<int, int>> mst;
    int sumOfMST = 0;
    pq.push({0, {0, -1}});
    while (!pq.empty())
    {
        auto topEle = pq.top();
        int currWt = topEle.first;
        int currNode = topEle.second.first;
        int currParent = topEle.second.second;
        pq.pop();
        if(visited[currNode]) continue;
        if (currParent != -1)
        {
            mst.push_back({currParent, currNode});
            sumOfMST += currWt;
        }
        visited[currNode] = 1;
        for (auto neighbour : adjList[currNode])
        {
            int neighbourNode = neighbour.first;
            int neighbourWt = neighbour.second;
            if (!visited[neighbourNode])
            {
                pq.push({neighbourWt, {neighbourNode, currNode}});
            }
        }
    }
    return sumOfMST;
}


int main()
{

    return 0;
}