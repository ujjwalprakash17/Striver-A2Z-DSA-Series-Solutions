#include <bits/stdc++.h>
using namespace std;

// int numSubarraysWithSum(vector<int> &nums, int goal)
// {
//     unordered_map<int, int>mp;
//     int prefixSum = 0;
//     int ans = 0;
//     for(int i = 0; i < nums.size() ; i++)
//     {
//         prefixSum += nums[i];
//         int rem = (prefixSum - goal);
//         //if found then 
//         if(mp.find(rem) != mp.end())
//         {
//             ans += mp[rem];
//         }
//         mp[prefixSum]++;
//     }
//     return ans;
// }

//New method , Old method niche hai prefix sum wala
// isme hm equal to goal pe nhi, less than or equal to goal wale pe jitne bhi subarrays hai count kr lenge aur phir goal se ek kam wale pe same krenge aur dono result ko subtract kr lenge. 
code : -

int main()
{
    string binRep = bitset<16>(10).to_string();
    cout << binRep << endl;
    cout << log2(7) + 1 << endl;
    return 0;
}