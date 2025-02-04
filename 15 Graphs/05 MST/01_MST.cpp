#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> visited(V, 0);
    pq.push({0, 0});
    int sum = 0;
    // visited[0] = 1;
    // we are pushing it like weight, node;
    while(!pq.empty())
    {
        int currNode = pq.top().second;
        int currWeight = pq.top().first;
        pq.pop();

        if(visited[currNode] == 1) continue;
        sum += currWeight;
        visited[currNode] = 1;

        for(auto it : adj[currNode]) { 
            int neighbourNode = it[0];
            int neighbourWeight = it[1];
            if(!visited[neighbourNode]){
                pq.push({neighbourWeight, neighbourNode});
            } 
        }
    }
    return sum;
}

int main()
{

    return 0;
}