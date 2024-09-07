#include <bits/stdc++.h>
using namespace std;

void countNGEVal(stack<int> &st, vector<int> &arr, int x, unordered_map<int, int> &mp)
{
    if(st.top() > x || st.empty())
    {
        mp[x] = st.size();
        return ;
    }
    int curr = st.top();
    st.pop();
    countNGEVal(st, arr, x, mp);;
    st.push(curr);
}

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    // write your code here
    stack<int> store;
    stack<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        if(store.empty())
        {

        }
        else{
            
        }
    }
}

int main()
{
    vector<int> sample = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices = {0, 5};
    vector<int> result = count_NGE(sample.size(), sample, 2, indices);
    //  = count_NGE();
    for (int i = 0; i < sample.size(); i++)
        cout << result[i] << " ";
    return 0;
}