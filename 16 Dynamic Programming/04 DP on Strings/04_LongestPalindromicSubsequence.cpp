#include <bits/stdc++.h>
using namespace std;

// int solution(int ind1, int ind2, string &s, vector<vector<int>> &dp)
// {
//     if (ind1 > ind2)
//         return 0;
//     if (ind1 == ind2)
//         return 1;
//     if (dp[ind1][ind2] != -1)
//         return dp[ind1][ind2];
//     // match case
//     if (s[ind1] == s[ind2])
//     {
//         return dp[ind1][ind2] = 2 + solution(ind1 + 1, ind2 - 1, s, dp);
//     }
//     // not match case
//     else
//     {
//         int movefirstBack = solution(ind1 + 1, ind2, s, dp);
//         int movesecondBack = solution(ind1, ind2 - 1, s, dp);
//         return dp[ind1][ind2] = max(movefirstBack, movesecondBack);
//     }
// }

// int longestPalindromeSubseq(string s)
// {
//     int n = s.size();
//     if (n == 1)
//         return 1;
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return solution(0, n - 1, s, dp);
// }

int longestPalindromeSubseq(string s1)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    cout << s2 << endl;
    int n = s1.length();
    vector<vector<int>>dp(n + 1, vector<int>(n+1, 0));
    for(int ind1 =  1; ind1 <= n ; ind1++)
    {
        for(int ind2 = 1 ; ind2 <= n ; ind2++)
        {
            if(s1[ind1-1] == s2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            }else{
                int moveFirstBack = dp[ind1][ind2-1];
                int moveSecondBack = dp[ind1-1][ind2];
                dp[ind1][ind2] = max(moveFirstBack, moveSecondBack);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    string s1 = "bbbab";
    cout << longestPalindromeSubseq(s1);

    return 0;
}