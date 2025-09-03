#include <bits/stdc++.h>
using namespace std;

//same binary subarray with sum wala concept jaha pr hm saari values less than or equal to wale pe nikalte hain aur usse km wale k ke value se subtract kr dete hain 

int countSubArrayWithAtMostK(vector<int> &nums, int k)
{
    int left = 0;
    int n = nums.size();
    int ans = 0;
    int oddCnt = 0;
    for (int right = 0; right < n; right++)
    {
        if (nums[right] & 1)
            oddCnt++;
        while (oddCnt > k)
        {
            if (nums[left] & 1)
                oddCnt--;
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return countSubArrayWithAtMostK(nums, k) - countSubArrayWithAtMostK(nums, k - 1);
}
int main()
{
    vector<int> sample =  {1,1,2,1,1};
    cout << numberOfSubarrays(sample, 2);

    return 0;
}