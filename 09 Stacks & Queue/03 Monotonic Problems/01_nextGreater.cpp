#include <bits/stdc++.h>
using namespace std;


// naive approach
//  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
//  {
//      unordered_map<int, int> mp;
//      for(int i = 0; i < nums2.size() ; i++)
//      {
//          mp[nums2[i]] = i;
//      }
//      vector<int> ans;
//      for(int i = 0; i < nums1.size() ; i++)
//      {
//          int ind = mp[nums1[i]];
//          int flag = 0;
//          for(int j = ind; j < nums2.size() ; j++)
//          {
//              if(nums2[j] > nums1[i])
//              {
//                  ans.push_back(nums2[j]);
//                  flag = 1;
//                  break;
//              }
//          }
//          if(flag == 0)
//          ans.push_back(-1);
//      }
//      return ans;
//  }
//  T.C - O(n) S.C - O(n);

// better approach
// why don't we start iterating from back
// also this leetcode question it is not much efficient, 
// but for the successor of next greater element this is an very important approach

// so approach : 



vector<int> nextGreaterElement(vector<int>& nums1, vector<int> &nums2)
{
    int n = nums2.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            st.push(nums2[i]);
            ans[i] = -1;
        }
        else
        {
            while (!st.empty() && nums2[i] >= st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
                st.push(nums2[i]);
            }
            else
            {
                ans[i] = st.top();
                st.push(nums2[i]);
            }
        }
    }
    vector<int> result;
    for(int i = 0; i < nums1.size(); i++)
    {
        for(int j = 0; j < nums2.size() ; j++)
        {
            if(nums1[i] == nums2[j])
            {
                result.push_back(ans[j]);
            }
        }
    }
    return result;
}

int main()
{
    vector<int> sample1 = {4 ,1 ,2};
    vector<int> sample2 = {1,3, 4 ,2};
    vector<int> result = nextGreaterElement(sample1, sample2);
    for(int i = 0; i < result.size() ; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}