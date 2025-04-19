#include <bits/stdc++.h>
using namespace std;

int solution(string word1, string word2)
{
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int ind1 = 1; ind1 <= n ; ind1++)
    {
        for(int ind2 = 1; ind2 <= m ; ind2++)
        {
            if(word1[ind1-1] == word2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }
            else{
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }
    return dp[n][m];
}

int minDistance(string word1, string word2) {
    int lcs = solution(word1, word2);
    int ans = (word1.size() - lcs) + (word2.size() - lcs);
    return ans;
}

int main() {
    
    return 0;
}