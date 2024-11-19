#include <bits/stdc++.h>
using namespace std;

int solution(int ind, vector<int> &nums, vector<int> &dp)
{
    // base case
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = nums[ind] + solution(ind - 2, nums, dp);
    int notPick = solution(ind - 1, nums, dp);
    return dp[ind] = max(pick, notPick);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int notPick = 0;
        if (i > 0)
            notPick += dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

int main()
{

    return 0;
}