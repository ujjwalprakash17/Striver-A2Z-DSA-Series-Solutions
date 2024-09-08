#include <bits/stdc++.h>
using namespace std;

vector<int> findNextSmallerEle(vector<int> &arr)
{
    stack<int> st;
    vector<int> store(arr.size());
    for(int i = arr.size() -1 ; i >= 0 ; i--)
    {
        if(st.empty())
        {
            store[i] = -1;
            st.push(arr[i]);
        }
        else{
            while(!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                store[i] = -1;
                st.push(arr[i]);
            }
            else{
                store[i] = st.top();
                st.push(arr[i]);
            }
        }
    }
    return store;
}

vector<int> findPrevSmallerEle(vector<int> &arr)
{
    vector<int> store(arr.size());
    stack<int> st;
    for(int i = 0; i < arr.size() ; i++)
    {
        if(st.empty())
        {
            store[i] = -1;
            st.push(arr[i]);
        }
        else{
            while(!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                store[i] = -1;
                st.push(arr[i]);
            }
            else{
                store[i] = st.top();
                st.push(arr[i]);
            }
        }
    }
    return store;
}

int sumSubarrayMins(vector<int> &arr)
{
    vector<int> nse = findNextSmallerEle(arr);
    vector<int> revArr = arr;
    reverse(revArr.begin() , revArr.end());
    revArr = findNextSmallerEle(revArr);
    reverse(revArr.begin(), revArr.end());
    
    
}

int main()
{
    vector<int> sample = {3, 1, 2, 4};
    cout << sumSubarrayMins(sample);
    return 0;
}