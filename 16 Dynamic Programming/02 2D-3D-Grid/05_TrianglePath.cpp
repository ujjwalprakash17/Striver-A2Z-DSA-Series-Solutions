#include <bits/stdc++.h>
using namespace std;

// int solution(int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
// {
//     //base case
//     if(n == 0) return triangle[0][0];

//     //main case
//     int minVal = INT_MAX;
//     for(int i = 0; i < n ; i++){
//         if(dp[n][i] != -1) return dp[n][i];
//         int val = triangle[n][i] + solution(n-1, triangle, dp);
//         minVal = min(minVal, val);
//         dp[n][i] = minVal;
//     }
//     return minVal;
// }

// Read the question properly :
//  you can only access the i th index or i + 1th index in next row, if we are moving from 0th row to nth row
// 1. there is an addition condition check that if last falls out of the condition such as if there is only one element then it will throw error so fix that as well,
// 2. otherwise the approach is simple,
// everytime when you move to the next row just check the current index and current index + 1th element which one is minimum
int solution(int n, int last, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    // base case
    if (n == triangle.size() - 1)
    {
        if (last < n)
            return min(triangle[n][last], triangle[n][last + 1]);
        return triangle[n][last];
    }
    // main case
    if (dp[n][last] != -1)
        return dp[n][last];
    int currVal = triangle[n][last] + solution(n + 1, last, triangle, dp);
    int nextVal = INT_MAX;
    if (last < n)
        nextVal = triangle[n][last + 1] + solution(n + 1, last + 1, triangle, dp);
    return dp[n][last] = min(currVal, nextVal);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = vector<int>(i + 1, -1);
    }
    return solution(0, 0, triangle, dp);
}
int main()
{
    // vector<vector<int>> sample =

    return 0;
}