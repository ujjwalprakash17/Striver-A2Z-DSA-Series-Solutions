#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    //
    int left = 0, right = 0;
    int n = nums.size();
    int cnt = 0, ans = INT_MIN;
    while (right < n)
    {
        if(nums[right] == 0) cnt++;
        while(cnt > k)
        {
            if(nums[left] == 0) cnt--;
            left++;
        }
        ans = max(ans, right -left  +1);
        right++;
    }
    return ans;
    
}

int main()
{

    return 0;
}