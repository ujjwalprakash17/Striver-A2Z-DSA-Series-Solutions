#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    //base case
    if(n == 0) return triangle[0][0];

    //main case 
    int minVal = INT_MAX;
    for(int i = 0; i < n ; i++){
        if(dp[n][i] != -1) return dp[n][i];
        int val = triangle[n][i] + solution(n-1, triangle, dp);
        minVal = min(minVal, val);
        dp[n][i] = minVal;
    }
    return minVal;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n);
    for(int i = 0; i < n ; i++)
    {
        dp[i] = vector<int> (i+1, -1);
    }
    return solution(n-1, triangle, dp);
}

int main()
{

    return 0;
}