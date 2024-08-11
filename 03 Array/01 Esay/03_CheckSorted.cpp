// Check if Array Is Sorted and Rotated
#include <bits/stdc++.h>
using namespace std;

//Approach : 
 Ex - 1 : 3 4 5 1 2
 in this case the loop will increase the count by 1 since 5 > 1
 but after loop will check that if first value is less than last value if yes increase 
 consider the below examples and dry run each 
 3 4 5 1 2, // true
 1 2 3 4 5,  // true 
 2 1 3 4 // false 



bool check(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    for(int i = 0; i < nums.size() - 1 ; i++)
    {
        //check if left value is greater than the right one 
        if(nums[i] > nums[i+1])
        cnt++;
    }
    //case - 2 : check the first and last value for sorted rotated
    if(nums[0] < nums[n-1]) // if the value is smaller then increase the count
    cnt++;
    if(cnt >= 2)
    return false;
    return true;
}

int main()
{

    return 0;
}