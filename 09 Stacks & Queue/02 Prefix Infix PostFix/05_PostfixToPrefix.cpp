#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string &str)
{
    vector<string> st;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
        {
            string s (1, str[i]);
            st.push_back(s);
        }
        else{
            int d = st.size();
            string temp = str[i] + st[d-2] + st[d-1]; 
            st.pop_back();
            st.pop_back();
            st.push_back(temp);
        }
    }
    return st[0];
}

int main()
{
    string str = "AB-DE+F*/";
    cout << postfixToPrefix(str) << endl;

    return 0;
}