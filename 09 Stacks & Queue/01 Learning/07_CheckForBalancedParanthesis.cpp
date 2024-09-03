#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char>st;
    for(int i = 0; i < s.size() ; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        st.push(s[i]);
        else if(s[i] == ')')
        {
            if(st.top() != '(') return false;
            st.pop();
        }
        else if(s[i] == '}')
        {
            if(st.top() != '{') return false;
            st.pop();
        }
        else if(s[i] == ']')
        {
            if(st.top() != '[') return false;
            st.pop();
        }
    }
    if(st.empty()) return true;
    return false;
}

int main()
{

    return 0;
}