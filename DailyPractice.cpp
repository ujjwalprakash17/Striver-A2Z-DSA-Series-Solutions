#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<vector<int>> &grid, int x)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> flattenArr(m * n);
    // flatten the array first
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            flattenArr[k++] = grid[i][j];
        }
    }
    // check for feasibility
    int remValue= flattenArr[0] % x;
    int arrSize = flattenArr.size();
    for(int i = 0; i < arrSize ; i++)
    {
        if(flattenArr[i] % k != remValue) return -1;
    }
    //now we will try to find the middle point
    sort(flattenArr.begin(), flattenArr.end());
    int midPointValue = flattenArr[arrSize / 2];
    int totalNumberOfSteps = 0;
    for(int i = 0; i < arrSize ; i++)
    {
        totalNumberOfSteps += (abs(flattenArr[i] - midPointValue)) / x;
    }
    return totalNumberOfSteps;
}

int main()
{

    return 0;
}