
#include <bits/stdc++.h>
using namespace std;

int solution(int ind, int target, vector<int> &nums)
{
   
    if(ind < 0)
        return target == 0;
    
    int takePos = solution(ind-1, target + nums[ind], nums);
    int takeNeg = solution(ind - 1, target - nums[ind], nums);
    return takePos + takeNeg;
}

int findTargetSumWays(vector<int> &nums, int target)
{   
    int n = nums.size();
    
    return solution(n-1, target, nums);
}

int main()
{

    return 0;
}
