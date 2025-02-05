#include <bits/stdc++.h>
using namespace std;

// Algorithm
//  1. initial configuration : a. min heap pq b. visited array c. mst storing vector, and ans variable

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, -1}});
    vector<pair<int,int>> mst;
    int sum = 0;
    vector<int> visited(V, 0);
    visited[0] = 1;
    while (!pq.empty())
    {
        //
        int currNode = pq.top().second.first;
        int parentNode = pq.top().second.second;
        int currWeight = pq.top().first;
        //mark those nodes visited who are not visited yet, also do not mark -1 as visited
        //put them in mst array
        if(parentNode != -1 && !visited[currNode]){
            mst.push_back({currNode, parentNode});
            visited[currNode] = 1;
            sum += currWeight;
        }
        //sum them up into sum variable
        // ...
        pq.pop();
        for(auto it : adj[currNode])
        {
            // put those edge weights who are not marked visited
            int neighbourNode = it.front().[0];
            
            // if(!visited[])
        }
    }
}

int main()
{

    return 0;
}