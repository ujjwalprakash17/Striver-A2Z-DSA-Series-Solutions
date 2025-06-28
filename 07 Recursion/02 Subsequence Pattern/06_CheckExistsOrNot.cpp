#include <bits/stdc++.h>
using namespace std;

bool solution(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (ind == arr.size())
    {
        return target == 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notPick = solution(ind + 1, arr, target, dp);
    bool pick = false;
    if (arr[ind] <= target)
    {
        pick = solution(ind + 1, arr, target - arr[ind], dp);
    }

    return dp[ind][target] = pick || notPick;
}

bool checkSubsequenceSum(int n, vector<int> &arr, int k)
{
    // Code here
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solution(0, arr, k, dp);
}

int main()
{

    return 0;
}