#include <bits/stdc++.h>
using namespace std;
// //step 1 : recursion
// int solution(int n, vector<int> &arr)
// {
//     if (n == 0)
//         return 0;
//     if (n >= 2)
//     {
//         int diff1 = abs(arr[n] - arr[n - 2]);
//         int diff2 = abs(arr[n] - arr[n - 1]);
//         return min(diff1 + solution(n-2, arr) , diff2 + solution(n-1,arr));
//     }
//     return abs(arr[1] - arr[0]);
// }
//step 2 : recursion + memoization
// int solution(int n, vector<int> &arr, vector<int> &dp)
// {
//     //base case 
//     if (n == 0)
//         return 0;
//     //check recursive
//     if(dp[n] != -1)
//     return dp[n];
//     if (n >= 2)
//     {
//         int diff1 = abs(arr[n] - arr[n - 2]);
//         int diff2 = abs(arr[n] - arr[n - 1]);
//         return dp[n] =  min(diff1 + solution(n-2, arr, dp) , diff2 + solution(n-1,arr, dp));
//     }
//     return dp[n] =  abs(arr[1] - arr[0]);
// }

//step 3 : tabulation
int solution(int n, vector<int> &arr)
{
    //base case 
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    for(int i = 2; i < n ;i++)
    {
        int diff1 = abs(arr[i] - arr[i-2]);
        int diff2 = abs(arr[i] - arr[i-1]);
        dp[i] = min(diff1 + dp[i-2], diff2 + dp[i-1]);
    }
    return dp[n-1];
}


int main()
{
    vector<int> height = {10, 20, 30, 10};
    vector<int> dp(height.size() , -1);
    cout << solution(4 -1 , height) << endl;

    return 0;
}