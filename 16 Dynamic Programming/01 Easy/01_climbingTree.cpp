#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> &dp)
{
    if(n <= 1)
    return 1;
    if(dp[n] != -1)
    return dp[n];
    dp[n] = solution(n - 1, dp) + solution(n -2, dp );

}

int main()
{
    int n = 3;
    vector<int> dp(n + 1, -1);
    cout << solution(n, dp);
    return 0;
}