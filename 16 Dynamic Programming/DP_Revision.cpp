#include <bits/stdc++.h>
using namespace std;

void findArr(int ind, vector<int> &nums, vector<int> &hasmmap, vector<int>&ans)
{
    if(hasmmap[ind] == ind) 
    {
        ans.push_back(nums[ind]);
        return;
    }
    findArr(hasmmap[ind], nums, hasmmap, ans);
    ans.push_back(nums[ind]);
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> store(n, 1);
    vector<int> hashmap(n);
    for(int i = 0; i < n ; i++) hashmap[i] = i;
    int maxLength = 1;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < i ; j++)
        {
            if((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) && store[i] < 1 + store[j])
            {
                store[i] = 1 + store[j];
                hashmap[i] = j;
                maxLength = max(maxLength, store[i]);
            }
        }
    }
    for(int ele : hashmap)
    {
        cout << ele << " ";
    }
    vector<int>ans;
    for(int i = 0; i < n ; i++)
    {
        if(store[i] == maxLength)
        {
            findArr(i, nums, hashmap, ans);
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> sample = {4, 8, 10, 240};
    sample = largestDivisibleSubset(sample); 
    // for(int ele : sample)
    // cout << ele << " ";
    return 0;
}

































// int sol(int ind, int maxInd, vector<int> &nums)
// {
//     int n = nums.size();
//     if(ind >= n){
//         return 0;
//     }
//     int notPick = sol(ind + 1, maxInd, nums);
//     int pick = 0;
//     if(nums[maxInd] % nums[ind] == 0 || nums[ind] % nums[maxInd] == 0){
//         pick = 1 + sol(ind + 1, nums[maxInd] > nums[ind] ? maxInd : ind, nums);
//     }
//     return max(pick, notPick);
// }

// int largestDivisibleSubset(vector<int> &nums)
// {
//     return sol(0, 0, nums);
// }
