#include <bits/stdc++.h>
using namespace std;
//Cycle Detection in graph using dfs
bool dfsTraversal(int start, vector<int> &visited, vector<int> &currPath, vector<vector<int>> &adjList)
{
    visited[start] = 1;
    currPath[start] = 1;
    for(int neighbour : adjList[start])
    {
        if(!visited[neighbour])
        {
            if(dfsTraversal(neighbour, visited, currPath, adjList)) return true;
        }else if(currPath[neighbour]){
            return true;
        }
    }
    currPath[start] = 0;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // convert this into adjList
    vector<vector<int>> adjList(numCourses);
    for(int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjList[v].push_back(u);
    }
    vector<int> visited(numCourses, 0);
    vector<int> currPath(numCourses, 0);
    //perform the cycle detection in a directed graph
    for(int i = 0; i < numCourses; i++)
    {
        if(!visited[i]){
            if(dfsTraversal(i, visited, currPath, adjList)) return false;
        }
    }
    return true;
}


int main()
{

    return 0;
}