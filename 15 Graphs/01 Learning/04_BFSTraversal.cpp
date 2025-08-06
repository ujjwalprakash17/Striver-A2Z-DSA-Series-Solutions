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

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    //step 1 : take a queue since bfs or levelOrder
                // take a array visited marked every element 0 -> initially
    queue<int> q;
    vector<int> visited(V,0);
    //since we have only one graph where we have considered the starting index as 0. you can choose any
    //so push the starting node into queue and mark it visited 
    q.push(0);
    visited[0] = 1;
    //take another array to store the bfs traversal 
    vector<int> bfs;
    //the below steps are repeating so keep repeating until the queue doesn't gets empty
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        bfs.push_back(curr);
        for(int it : adj[curr])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
    
}

int main()
{

    return 0;
}