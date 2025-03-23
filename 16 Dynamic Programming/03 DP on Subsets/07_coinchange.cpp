#include <bits/stdc++.h>
using namespace std;


int solution(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (ind < 0)
        return amount == 0 ? 0 : 1e9;
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int notPick = solution(ind - 1, amount, coins, dp);
    int pick = 1e9;
    if (coins[ind] <= amount)
        pick = 1 + solution(ind, amount - coins[ind], coins, dp);
    return dp[ind][amount] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, -1));
    int val = solution(n-1, amount, coins, dp);
    if(val == 1e9) return -1;
    return val;
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));
    // base case transformation
    dp[0][0] = 0;
    for (int ind = 1; ind <= n; ind++) {
        for (int amt = 0; amt <= amount; amt++) {
            int notPick = dp[ind - 1][amt];
            int pick = 1e9;
            if (coins[ind - 1] <= amt)
                pick = 1 + dp[ind][amt - coins[ind - 1]];
            dp[ind][amt] = min(pick, notPick);
        }
    }
    int val = dp[n][amount];
    if (val == 1e9)
        return -1;
    return val;
}
int main()
{

    return 0;
}