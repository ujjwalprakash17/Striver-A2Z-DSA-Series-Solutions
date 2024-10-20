// 931. Minimum Falling Path Sum
#include <bits/stdc++.h>
using namespace std;

int solution(int row, int col, vector<vector<int>> &matrix)
{
    if (row == 0)
    {
        int mini = INT_MAX;
        for (int k = col - 1; k <= col + 1; k++)
        {
            if (k >= 0 && k < matrix[0].size() - 1)
                mini = min(mini, matrix[row][k]);
        }
        return mini;
    }
    int mini = INT_MAX;
    for(int i = col - 1; i <= col + 1 ; i++)
    {
        int currVal = INT_MAX;
        if(i >= 0 && i < matrix.size() - 1)
        currVal = matrix[row][i] + solution(row -1, i, matrix);
        mini = min(mini, currVal);
    }
    return mini;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    // base case
    int n = matrix.size();
    return solution(0,)
}

int main()
{

    return 0;
}