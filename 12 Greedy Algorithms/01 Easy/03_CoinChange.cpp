#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    // sort the coin in reverse
    sort(coins.begin(), coins.end(), greater<int>());
    int ans = 0;
    int i = 0;
    while (i < coins.size())
    {
        if (amount >= coins[i])
        {
            ans++;
            amount -= coins[i];
        }
        else
        {
            i++;
        }
    }
    if (amount == 0)
        return ans;
    else
        return -1;
}

int main()
{
    vector<int> sample = {186,419,83,408};
    int amount = 6249;
    cout << coinChange(sample, amount) << endl;
    return 0;
}