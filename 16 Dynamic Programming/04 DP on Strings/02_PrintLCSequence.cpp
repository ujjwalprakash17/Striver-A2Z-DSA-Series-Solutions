#include <bits/stdc++.h>
using namespace std;

// tabulation
int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.length();
    int n2 = text2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int ind1 = 1; ind1 <= n1; ind1++)
    {
        for (int ind2 = 1; ind2 <= n2; ind2++)
        {
            if (text1[ind1 - 1] == text2[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }
            else
            {
                int firstString = dp[ind1 - 1][ind2];
                int secondString = dp[ind1][ind2 - 1];
                dp[ind1][ind2] = max(firstString, secondString);
            }
        }
    }
    int maxLength = dp[n1][n2];
    set<string> ans;
    for (int i = n1; i > 0;)
    {
        string temp = "";
        for (int j = n2; j > 0;)
        {
            if (text1[i] == text2[j])
            {
                temp = text1 + temp;
                i = i - 1, j = j - 1;
            }else{
                
            }
        }
        ans.insert(temp);
    }
}

vector<string> all_longest_common_subsequences(string s, string t)
{
    // Code here
}

int main()
{

    return 0;
}