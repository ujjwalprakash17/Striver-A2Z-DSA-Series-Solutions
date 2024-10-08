#include <bits/stdc++.h>
using namespace std;
// Approach : 
// very simple we need to add an extra condition to check whether this value of m & n has an obstacle or not if yes, 
// then will just return from the path


int solution(int m, int n, vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid ){
        if(obstacleGrid[m][n] == 1) return 0 ;
        else if(m == 0 && n == 0) {
            return 1;
        }
        if(dp[m][n] != -1) return dp[m][n];
        int left = 0, up = 0;
        if(m > 0){
            up = solution(m -1, n , dp, obstacleGrid);
        }
        if(n > 0){
            left = solution(m, n-1 , dp, obstacleGrid);
        }
        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //base case 
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n , -1));
        return solution(m-1, n-1, dp, obstacleGrid);
    }

int main()
{
    
    return 0;
}