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


vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    // special conditions
    //  1. right to left traverse krenge
    //  2. last element ke liye hamesh -1 dalenge
    //  3. agar stack me curr se bada hai toh jb tk pop kro jb tak stack empty na ho jaye ya phir koi bada element na mil jaye
    //  4. aur agar stk ke top pe bada element hai curr se toh top wale ko bade element me daal do aur curr wale ko push kr do
    int n1 = nums1.size();
    int n2 = nums2.size();
    unordered_map<int, int> mp;
    stack<int> stk;
    for (int i = n2 - 1; i >= 0; i--)
    {
        int currEle = nums2[i];
        if (i == n2 - 1)
        {
            mp[currEle] = -1;
        }
        else
        {
            while (!stk.empty() && stk.top() < currEle)
            {
                stk.pop();
            }
            if (stk.empty())
                mp[currEle] = -1;
            else
            {
                mp[currEle] = stk.top();
            }
        }
        stk.push(currEle);
    }
    vector<int> ans;
    for (int ele : nums1)
    {
        ans.push_back(mp[ele]);
    }
    return ans;
}

// Time Complexity Analysis Amortised --- Very interesting
// 1. first loop is running from n2 ---> 0 so O(n2) ~
// 2. since in while loop total opertions can be at max O(n2) - total push O(n2) * each iteration + O(n2) pop (since each element can be popped at once)
// 3. total time complexity is O(n2) + O(n2) + O(<= n2) which in total is O(n2);




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