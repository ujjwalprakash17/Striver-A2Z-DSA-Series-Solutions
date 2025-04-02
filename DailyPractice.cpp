#include <bits/stdc++.h>
using namespace std;

long long mostPoints(vector<vector<int>> &questions)
{
    int n = questions.size(); 
    vector<long long> dp(n + 1, 0);
    for(int ind = n -1  ; ind >= 0 ; ind--)
    {
        long long notPick = dp[ind+1];
        int nextIndex = ind + questions[ind][1] + 1;
        long long pick = questions[ind][0];
        if(nextIndex <= n){
            pick += dp[nextIndex];
        }
        dp[ind] = max(pick , notPick);
    }
    return dp[0];
}

long long solution(int ind, vector<vector<int>> &questions, vector<long long> &dp)
{
    int n = questions.size();
    if (ind >= n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    long long notPick = solution(ind + 1, questions, dp);
    long long pick = questions[ind][0] + solution(ind + (questions[ind][1] + 1), questions, dp);
    return dp[ind] = max(pick, notPick);
}

long long mostPoints(vector<vector<int>> &questions)
{
    int n = questions.size();
    // we will need an offset method because the value of ind could be varying
    vector<long long> dp(n, -1);
    return solution(0, questions, dp);
}


int main()
{
    vector<vector<int>> sample = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << mostPoints(sample);

    return 0;
}