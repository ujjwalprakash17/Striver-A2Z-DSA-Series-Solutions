#include <bits/stdc++.h>
using namespace std;

// int searchInsert(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     int s = 0, e = n -1;
//     int ans = -1;
//     while(s <= e)
//     {
//         int mid = s + (e-s)/2;
//         if(nums[mid] == target){
//             return mid;
//         }
//         else if(nums[mid] < target){
//             ans = mid;
//             s = mid + 1;
//         }
//         else{
//             e = mid - 1;
//         }
//     }
//     return ans + 1;
// }

int floorVal(vector<int> &a, int n , int x)
{
    int ans = -1;
    int s = 0, e = n - 1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(a[mid] > x){
            e = mid -1;
        }
        else {
            ans = a[mid];
            s = mid + 1;
        }
    }
    return ans;
}
int ceilVal(vector<int> &a, int n , int x)
{
    int ans = -1;
    int s = 0, e = n - 1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(a[mid] > x){
            ans = a[mid];
            e = mid -1;
        }
        else {
            // ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
    pair<int, int> ans;
    ans.first = floorVal(a, n, x);
    ans.second = ceilVal(a, n, x);
    return ans;
}

int main()
{
    vector<int> sample = {3,4, 4, 7, 8, 10};
    int target = 5;
    int n = sample.size();
    pair<int, int> p = getFloorAndCeil(sample, n, target);
    cout << p.first << " " << p.second << endl;
    return 0;
}