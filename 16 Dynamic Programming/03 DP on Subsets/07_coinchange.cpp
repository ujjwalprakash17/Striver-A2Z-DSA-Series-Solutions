#include <bits/stdc++.h>
using namespace std;

int solution(int ind, int amt, vector<int> &coins, vector<vector<int>> &dp)
{
    // base case
    if (amt == 0)
        return 0;
    if (ind == 0)
    {
        if (amt % coins[ind] == 0)
            return (amt / coins[ind]);
        return 1e9;
    }
    if (dp[ind][amt] != -1)
        return dp[ind][amt];
    int pick = 1e9;
    if (coins[ind] <= amt)
        pick = 1 + solution(ind, amt - coins[ind], coins, dp);
    int notPick = solution(ind - 1, amt, coins, dp);

    return dp[ind][amt] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int val = solution(n - 1, amount, coins, dp);
    if (val == 1e9)
        return -1;
    return val;
}


int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    //handle base cases correctly first
    for(int i = 0; i < n;  i++)
    {
        dp[i][0] = 0;
    }
    for(int amt = 0; amt <= amount ; amt++)
    {
        if(amt % coins[0] == 0)
        dp[0][amt] = amt / coins[0];
        else{
            dp[0][amt] = 1e9;
        }
    }

    for(int ind = 1 ; ind < n ; ind++)
    {
        for(int amt = 1 ; amt <= amount ; amt++)
        {
            int pick = 1e9;
            if(coins[ind] <= amt)
            pick = 1 + dp[ind][amt-coins[ind]];
            int notPick = dp[ind-1][amt];
            dp[ind][amt] = min(pick, notPick);
        }
    }
    return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    //return -1 if ans is 1e9
}


int main()
{

    return 0;
}