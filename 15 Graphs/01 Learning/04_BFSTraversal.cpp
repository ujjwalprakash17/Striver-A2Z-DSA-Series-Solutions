#include <bits/stdc++.h>
using namespace std;

// Function to return Breadth First Traversal of given graph.

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    //take a visited array
    int vis[V] = {0};
    //take a queue to store the traversal
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    //take a storage to store the traversal
    vector<int> bfs;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        //which ever is pop that must go into answer storage 
        bfs.push_back(curr);
        //visit all the neighbours of the current node 
        for(int i = 0; i < adj[curr].size(); i++)
        {
            if(!vis[adj[curr][i]])  //adj[curr] will point to the current node in adj list and [i] will visit all the values stored in it.
            {
                vis[adj[curr][i]] = 1;
                q.push(adj[curr][i]);
            }
        }
    }
    return bfs;
}


int main()
{

    return 0;
}