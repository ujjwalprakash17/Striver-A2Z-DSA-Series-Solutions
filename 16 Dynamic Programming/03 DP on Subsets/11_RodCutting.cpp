#include <bits/stdc++.h>
using namespace std;

int solution(int ind, int rodLength, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind < 0 || rodLength <= 0)
        return 0;

    if(dp[ind][rodLength] != -1) return dp[ind][rodLength];
    int notTake = solution(ind - 1, rodLength, price, dp);
    int take = 0;
    int currRodLength = ind + 1;
    if (currRodLength <= rodLength)
    {
        take = price[ind] + solution(ind, rodLength - currRodLength, price, dp);
    }
    return dp[ind][rodLength] = max(take, notTake);
}
int cutRod(vector<int> &price)
{
    // code here
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solution(n-1, n, price, dp);
}

//tabulation
int cutRod(vector<int> &price)
{
    // code here
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int ind = 1; ind <= n ; ind++){
        for(int rodLength = 1; rodLength <= n ; rodLength++)
        {
            int notTake = dp[ind -1][rodLength];
            int take = 0;
            int currRodLength = ind;
            if(currRodLength <= rodLength){
                take = price[ind-1] + dp[ind][rodLength-currRodLength];
            }
            dp[ind][rodLength] = max(take, notTake);
        }
    }
    return dp[n][n];
}




int main()
{
    vector<int> sample = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(sample);
    return 0;
}