#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < nums2.size() ; i++)
    {
        mp[nums2[i]] = i; 
    }
    vector<int> ans;
    for(int i = 0; i < nums1.size() ; i++)
    {
        int ind = mp[nums1[i]];
        int flag = 0;
        for(int j = ind; j < nums2.size() ; j++)
        {
            if(nums2[j] > nums1[i])
            {
                ans.push_back(nums2[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        ans.push_back(-1);
    }
    return ans;

}

int main()
{

    return 0;
}