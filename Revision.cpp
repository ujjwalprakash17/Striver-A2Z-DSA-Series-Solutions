#include <bits/stdc++.h>
using namespace std;

bool isCycleCheck(int start, vector<int> &visited, vector<int> &currPath, vector<vector<int>> &adjList, stack<int> &st)
{
    visited[start] = 1;
    currPath[start] = 1;
    for (int neighbour : adjList[start])
    {
        if (!visited[neighbour])
        {
            if (isCycleCheck(neighbour, visited, currPath, adjList, st))
                return true;
        }
        else if (currPath[neighbour])
        {
            return true;
        }
    }
    st.push(start);
    currPath[start] = 0;
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    // steps solve:
    // convert the prerequisites into and adjList
    vector<vector<int>> adjList(numCourses);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjList[v].push_back(u);
    }
    // perform the operation cycle detection in an undirected graph with an addition of storing elements in stack
    vector<int> visited(numCourses, 0);
    vector<int> currPath(numCourses, 0);
    stack<int> st;
    vector<int> result;
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (isCycleCheck(i, visited, currPath, adjList, st))
                return {};
        }
    }
    // pop the element from stack and push it into resultant vector
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        result.push_back(curr);
    }
    return result;
}

int main()
{

    return 0;
}