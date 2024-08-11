// Remove Duplicates from Sorted Array
#include <bits/stdc++.h>
using namespace std;

// approach : since we are required to solve "In-place"
//  so based on this approach we can take another index
//  and
//  whenever a new value is there only then we will update the index
//  that's all

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int ind = 0; 
    for(int i = 1; i < n ; i++)
    {
        if(nums[i] != nums[ind])
        {
            ind++;
            nums[ind] = nums[i];
        }
    }
    return ind + 1; //since they are asking for size not for index
}
// T.C - O(n) | S.C - O(1)



int main()
{
    vector<int> sample = {1,1,2};
    removeDuplicates(sample);

    return 0;
}