#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int start, vector<int> &color, vector<vector<int>> &adjList)
{

    color[start] = 1;
    for (int neighbour : adjList[start])
    {
        if (color[neighbour] == 0)
        {
            if (!detectCycle(neighbour, color, adjList))
                return false;
        }
        else if (color[neighbour] == 1)
            return false;
    }
    color[start] = 2;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    for (auto prereq : prerequisites)
    {
        int u = prereq[0];
        int v = prereq[1];
        adjList[v].push_back(u);
    }
    vector<int> color(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        if (!color[i])
        {
            bool val = detectCycle(i, color, adjList);
            if (!val)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}