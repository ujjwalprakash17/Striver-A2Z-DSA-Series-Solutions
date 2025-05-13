#include <bits/stdc++.h>
using namespace std;

int solution(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if(ind >= n){
        return 0;
    }
    if(dp[ind][prev+1] != -1) return dp[ind]
    int notPick = solution(ind + 1, prev, nums, dp);
    int pick = 0;
    if(prev == -1 || nums[prev] < nums[ind])
    {
        pick = 1 + solution(ind + 1, ind, nums, dp);
    }
    return dp[ind][prev+1] = max(pick, notPick);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return solution(0, -1, nums, dp);
}

int main()
{

    return 0;
}

