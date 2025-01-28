#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    // Code here
    set<pair<int, int>> st;
    st.insert({0, src});
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        int currNode = it.second;
        int currDist = it.first;
        st.erase(st.begin());
        // look for neighbours who are at a shorter distance
        // also if a neighbour is not equal to INT_MAX; make sure to remove that from set
        for (auto it : adj[currNode])
        {
            int neighbourNode = it.first;
            int neighbourWeight = it.second;
            if (currDist + neighbourWeight < dist[neighbourNode])
            {
                if (dist[neighbourNode] != INT_MAX)
                {
                    st.erase({dist[neighbourNode], neighbourNode});
                }
                st.insert({currDist + neighbourWeight, neighbourNode});
                dist[neighbourNode] = currDist + neighbourWeight;
            }
        }
    }
    return dist;
}

int main()
{

    return 0;
}