#include <bits/stdc++.h>
using namespace std;
//step 1 : Recursive solution
// int solution(int n)
// {
//     if(n <= 1)
//     return 1;
//     return solution(n - 1) + solution(n -2);
// }


//step 2 : Recursive + Memoization solution
// int solution(int n, vector<int> &dp)
// {
//     if(n <= 1)
//     return 1;
//     if(dp[n] != -1)
//     return dp[n];
//     dp[n] = solution(n - 1, dp) + solution(n -2, dp );
// }
// T.C - O(n) , S.C - O(n)

// step 3: Tabulation problem
 int solution(int n)
 {
     vector<int> dp(n+1);
     dp[1] = 1;
     dp[0] = 0;
     for(int i = 2 ; i <= n ; i++)
     {
         dp[i] = dp[i-1] + dp[i-2];
     }
     return dp[n];
}
// T.C - O(n) , S.C - O(n)


int main()
{
    int n = 3;
    vector<int> dp(n + 1, -1);
    cout << solution(n, dp);
    return 0;
}