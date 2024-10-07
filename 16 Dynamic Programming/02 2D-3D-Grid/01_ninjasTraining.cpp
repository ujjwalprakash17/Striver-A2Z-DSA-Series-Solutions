#include <bits/stdc++.h>
using namespace std;
// //recusion solution
// int solution(int n, int last, vector<vector<int>> &arr)
// {
//     // base case
//     if (n == 0)
//     {
//         int maxi = 0;
//         for (int i = 0; i < 3; i++)
//         {
//             if (i != last)
//                 maxi = max(maxi, arr[0][i]);
//         }
//         return maxi;
//     }
//     // main case 
//     int maxi = INT_MIN;
//     for(int i = 0; i < 3 ;i++)
//     {
//         if(i != last)
//         {
//             int points = arr[n][i] + solution(n-1, i, arr);
//             maxi = max(maxi, points);
//         }
//     }
//     return maxi;
// }
//memoization solution
int solution(int n, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    // base case
    if (n == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, arr[0][i]);
        }
        return maxi;
    }
    //dp condition check 
    if(dp[n][last] != -1) return dp[n][last];
    // main case 
    int maxi = INT_MIN;
    for(int i = 0; i < 3 ;i++)
    {
        if(i != last)
        {
            int points = arr[n][i] + solution(n-1, i, arr, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[n][last] = maxi;
}

int maximumPoints(vector<vector<int>> &arr, int n)
{
    // Code here
    // memoization solution
    vector<vector<int>> dp(n + 1, vector<int> (4, -1));
    return solution(n-1, 3, arr, dp);
}

int main()
{

    return 0;
}