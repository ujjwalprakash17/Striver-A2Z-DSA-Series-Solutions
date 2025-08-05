#include <bits/stdc++.h>
using namespace std;

//My approach to find the shortest time to visit all nodes is 
// the maximum time taken in visiting any of the nodes is the minimum time taken to visit all nodes
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // find the minimum time
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (auto &time : times)
    {
        int u = time[0];
        int v = time[1];
        int wt = time[2];
        adjList[u].push_back({v, wt});
    }
    // check if any of the node is not sent signals then return -1
    vector<int> timeTaken(n + 1, 1e9);
    timeTaken[k] = 0;
    set<pair<int, int>> setDs;
    // storing like {timeTaken, node}
    setDs.insert({0, k});
    while (!setDs.empty())
    {
        auto currEle = setDs.begin();
        int currTimeTaken = currEle->first;
        int currNode = currEle->second;
        setDs.erase(setDs.begin());
        for (auto neighbour : adjList[currNode])
        {
            int neighbourNode = neighbour.first;
            int neighbourTime = neighbour.second;
            int newTimeTaken = currTimeTaken + neighbourTime;
            if (newTimeTaken < timeTaken[neighbourNode])
            {
                if (timeTaken[neighbourNode] != 1e9)
                {
                    setDs.erase({timeTaken[neighbourNode], neighbourNode});
                }
                setDs.insert({newTimeTaken, neighbourNode});
                timeTaken[neighbourNode] = newTimeTaken;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (timeTaken[i] == 1e9)
            return -1;
        ans = max(ans, timeTaken[i]);
    }
    return ans;
}

int main()
{

    return 0;
}