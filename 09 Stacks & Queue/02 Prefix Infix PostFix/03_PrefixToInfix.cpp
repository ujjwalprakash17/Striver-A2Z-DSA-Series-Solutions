#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string &str)
{
    vector<string> st;
    //access from back and 
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
        {
            string s(1, str[i]);
            st.push_back(s);
        }
        else{
            //take out last two elements
            string op1 = st.back(); st.pop_back();
            string op2 = st.back(); st.pop_back();
            //create a new expression and push it back into the stack
            string temp = "(" + op1 + str[i] + op2 + ")";
            st.push_back(temp);
        }
    }
    return st[0];
}

int main()
{
    string sample = "";
    cout << prefixToInfix(sample) << endl;

    return 0;
}