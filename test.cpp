#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{
    vector<vector<int>> ans(m, vector<int>(n));
    if (m * n < original.size())
        return ans;
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = original[k++];
        }
    }
    return ans;
}

int main()
{

    return 0;
}