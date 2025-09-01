#include <bits/stdc++.h>
using namespace std;
// my approach without using monotonic stack
int celebrity(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    vector<int> outdegree(n, 0);
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = mat[i][j];
            if (val)
            {
                outdegree[i]++;
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (outdegree[i] == 1 && indegree[i] == n)
            return i;
    }
    return -1;
}
// T.C - O(n * n) where n = number of rows
// space complexity : O(n)

// Okay for the fact we know that there can only be 1 celebrity how?
// since the condition state that : known by everyone, and knows no one

// fact :
// maximum number of celebrity = 1 and minimum number of celebrity = 0
// we will take advantage of this fact

int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    int top = 0, down = n - 1;
    while (top < down)
    {
        if (mat[top][down] == 1)
            top++; // top knows down → top can't be celeb
        else
            down--; // top does not know down → down can't be celeb
    }
    if (top > down)
        return -1; // means there could not be a celebrity
    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;
        if (mat[top][i] == 1)
            return -1; // celeb should not know others
        if (mat[i][top] == 0)
            return -1; // everyone must know celeb
    }
    return top;
}

int main()
{

    return 0;
}