#include <bits/stdc++.h>
using namespace std;


// approach : we are doing reverse engineering and trying to find out that target - currentValue = another value
// we can understand it like this 
// x + y =target => x = target - y; 
// so we are looking for any x who is present in the map, 
// every time on new value of y. 

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n ; i++)
    {
        int rem = target - nums[i];
        //if found 
        if(mp.find(rem) != mp.end())
        {
            return {mp[rem], i}; // if found case 
        }
        //not found
        else {
            mp[nums[i]] = i;
        }
    }
    // if not then
    return {-1, -1};
}

// T.C - O(n) | S. C - O(n);


int main()
{

    return 0;
}