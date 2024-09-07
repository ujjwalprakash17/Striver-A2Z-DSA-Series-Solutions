#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int d = nums.size();
    vector<int> store(d);
    stack<int> st;
    for(int i = 2 * d - 1; i >= 0 ; i--)
    {
        if(st.empty())
        {
            st.push(nums[i%d]);
            store[i%d] = -1;
        }
        else{
            while(!st.empty() && nums[i%d] >= st.top())
            {
                st.pop();
            }
            if(st.empty()) store[i%d] = -1;
            else store[i%d] = st.top();
            st.push(nums[i%d]);
        }
    }
    return store;
}

int main()
{
    vector<int> sample = {5,4 ,3 ,2 ,1 };
    vector<int> result = nextGreaterElements(sample);
    for(int i = 0; i < result.size(); i++)
    cout << result[i] << " ";

    return 0;
}