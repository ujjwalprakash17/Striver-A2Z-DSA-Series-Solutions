#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> &height, vector<int> &dp)
{
    if (n == 0)
        return 0;
    int oneStep = INT_MAX;
    int twoStep = INT_MAX;
    if(dp[n] != -1) return dp[n];
    if (n > 0)
        oneStep = solution(n - 1, height, dp) + abs(height[n] - height[n - 1]);
    if (n > 1)
        twoStep = solution(n - 2, height, dp) + abs(height[n] - height[n - 2]);
    return dp[n] = min(oneStep, twoStep);
}
int minCost(vector<int> &height)
{
    // Code here
    int n = height.size();
    vector<int> dp(n, -1);
    return solution(n - 1, height, dp);
}

int main()
{
    vector<int> height = {10, 30, 40, 20, 50};
    cout << minCost(height);

    return 0;
}