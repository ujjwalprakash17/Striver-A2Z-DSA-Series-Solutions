// 33. Search in Rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;

// Approach :
// Step - 1: Try to find out the pivot value, means the lowest or minimum value
//     case 1 : if target > pivot and last value then value must be in the first part

// case 2: if target is greater than pivot element but lesser than the last value then the value must be in the first half

// step 2 : pass the halves to the binarySearch function and they will do the rest

// int binarySearch(vector<int> &nums, int s, int e, int target)
// {
//     while (s <= e)
//     {
//         int mid = s + (e - s) / 2;
//         if (nums[mid] == target)
//             return mid;
//         else if (nums[mid] > target)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//     }
//     return -1;
// }

// int getPivot(vector<int> &nums)
// {
//     int n = nums.size();
//     int s = 0, e = nums.size() - 1;
//     while (s < e)
//     {
//         int mid = s + (e - s) / 2;
//         if (nums[e] < nums[mid])
//             s = mid + 1;
//         else
//         {
//             e = mid;
//         }
//     }
//     return s % n;
// }

// int search(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     int pivotInd = getPivot(nums);
//     if (target > nums[pivotInd] && target > nums[n - 1])
//         return binarySearch(nums, 0, pivotInd - 1, target);
//     return binarySearch(nums, pivotInd, n - 1, target);
// }

int getPivot(vector<int> &nums)
{
    int n = nums.size();
    int s = 0, e = n -1;
    while(s < e)
    {
        int mid = s + (e-s) /2;
        if(nums[e] < nums[mid])
        s = mid + 1;
        else 
        e = mid ;
    }
    return s % n;
}

// int search(vector<int> &nums, int target)
// {

// }

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << getPivot(nums) << endl;

    return 0;
}