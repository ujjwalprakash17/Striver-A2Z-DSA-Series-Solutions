#include <bits/stdc++.h>
using namespace std;

//same binary subarray with sum wala concept jaha pr hm saari values less than or equal to wale pe nikalte hain aur usse km wale k ke value se subtract kr dete hain 

int noOfSubarrayLessthanOrEqual(vector<int> &nums, int k)
{
    if(k < 0) return 0;
    int totalSubarray = 0;
    int left = 0, right = 0;
    int n = nums.size();
    int oddCnt = 0;
    while(right < n)
    {
        if(nums[right] % 2 != 0) oddCnt++;
        //agar count k se jayeda ho gya tb
        while(oddCnt > k)
        {
            if(nums[left] % 2 != 0) oddCnt --;
            left++;
        }
        //value ans me store kra lo
        totalSubarray += (right - left + 1);
        right++;
    }
    return totalSubarray;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return noOfSubarrayLessthanOrEqual(nums, k) - noOfSubarrayLessthanOrEqual(nums, k-1);
}

int main()
{
    vector<int> sample =  {1,1,2,1,1};
    cout << numberOfSubarrays(sample, 2);

    return 0;
}