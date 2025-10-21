#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int cnt = 1, ans = 1;
    int tempK = k, tempNumOp = numOperations;
    for(int i = 0; i < n - 1; i++)
    {
        if(nums[i] + tempK >= nums[i+1]){
            cnt++;
            tempNumOp--;
            if(tempNumOp == 0) tempK = 0;
        }else{
            
        }
    }
    return ans;
}

int main()
{
    vector<int> sample = {1, 2, 3, 4};

    return 0;
}