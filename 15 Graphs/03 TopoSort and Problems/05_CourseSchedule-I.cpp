#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &pair1, vector<int> &pair2 )
{
    return pair1[1] < pair2[1];
}

bool dfsTraversal(int numCourses, vector<vector<int>> &prerequisites, stack<pair<int, int>> &st)
{
    pair<int, int> topEle = st.top();
    if(topEle.first == prerequisites[numCourses][1])
    return false;
    else 
    {
        if(dfsTraversal(numCourses + 1, prerequisites, st) == false)
        return false;
    }
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    stack<pair<int, int>> st;
    sort(prerequisites.begin(), prerequisites.end(), comp);
    return dfsTraversal(numCourses, prerequisites, st);
}

int main()
{

    return 0;
}