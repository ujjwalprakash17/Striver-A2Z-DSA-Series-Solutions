#include <bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MIN;
    int inc = 1, dec = 1;
    for(int i = 0; i < n ;i++){
        if(nums[i] > nums[i+1]){
            dec = 1;
            inc++;
        }else if(nums[i] < nums[i+1]) {
            inc = 1;
            dec++;
        }else{
            inc = 1;
            dec = 1;
        }
        ans = max(ans, max(inc, dec));
    }
    return ans;
}
int main()
{

    return 0;
}