#include <bits/stdc++.h>
using namespace std;

// approach : is case me hm apne pichhle questions ke tabulation method se sikhenge
//  ki how table is being filled
// but in case of substring jb bhi koi naya character dusre string ke last character se match nhi hoga (tabulation)
// tab hm instead of max(row-1, col) and (row, col-1) ke badle hm simply 0 rakh denge
// that is all
// our modified code will look some thing like below

int longestCommonSubstr(string &s1, string &s2)
{
    // your code here
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int ans = 0;
    for (int ind1 = 1; ind1 <= n1; ind1++)
    {
        for (int ind2 = 1; ind2 <= n2; ind2++)
        {
            if (s1[ind1-1] == s2[ind2-1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                ans = max(ans, dp[ind1][ind2]);
            }
            else
            {
                dp[ind1][ind2] = 0;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}