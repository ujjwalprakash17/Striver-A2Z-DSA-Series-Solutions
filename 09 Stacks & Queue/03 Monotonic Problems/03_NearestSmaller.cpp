#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    stack<int> st;
    vector<int> result(A.size());
    for(int i = 0; i < A.size() ; i++)
    {
        if(st.empty())
        {
            st.push(A[i]);
            result[i] = -1;
        }
        else{
            while(!st.empty() && A[i] <= st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push(A[i]);
                result[i] = -1;
            }
            else{

                result[i] = st.top();
                st.push(A[i]);
            }
        }
    }
    return result;
}

int main()
{
    vector<int> sample = {4, 5, 2, 10, 8};
    vector<int> result = prevSmaller(sample);
    for(int i = 0; i < result.size() ; i++)
    cout << result[i] << " ";

    return 0;
}