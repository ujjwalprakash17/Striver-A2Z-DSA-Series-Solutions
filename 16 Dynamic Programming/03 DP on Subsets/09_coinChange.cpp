#include <bits/stdc++.h>
using namespace std;

int solution(int ind, int amount, vector<int> &coins, vector<vector<int>>&dp)
{
    // base case
    if (amount == 0)
        return 1;
    if (ind == 0)
        return (amount % coins[0] == 0) ? 1 : 0;
    if(dp[ind][amount] != -1) return dp[ind][amount];
    int notPick = solution(ind - 1, amount, coins, dp);
    int pick = 0;
    if (coins[ind] <= amount)
        pick = solution(ind, amount - coins[ind], coins, dp);
    return dp[ind][amount] = pick + notPick;
}

int change(int amount, vector<int> &coins)
{
    // base case
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
    return solution(n-1, amount, coins, dp);
}


int change(int amount, vector<int> &coins)
{
    // base case
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amount + 1, 0));
    
    //for any value of ind if amount == 0 return 1;
    for(int i = 0 ; i < n;  i++)
    dp[i][0] = 1;
    for(int amt = 1 ; amt <= amount; amt++)
    dp[0][amt] = (amt % coins[0] == 0) ? 1 : 0;

    for(int i = 1; i < n ; i++)
    {
        for(int amt = 1 ; amt <= amount ; amt++)
        {
            int notPick = dp[i-1][amt];
            int pick = 0;
            if(coins[i] <= amt)
            pick = dp[i][amt-coins[i]];
            dp[i][amt] = pick + notPick;
        }
    }
    return dp[n-1][amount];

}

int main()
{
    vector<int> sample = {1,2 ,5};
    int amount = 5;
    cout << change(5, sample);

    return 0;
}