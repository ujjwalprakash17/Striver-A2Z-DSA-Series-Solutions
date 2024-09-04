#include <bits/stdc++.h>
using namespace std;

int checkPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
    {
        return -1;
    }
}

string infixToPostfix(string &str)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9'))
        ans += str[i];
        else if(str[i] == '(')
        st.push(str[i]);
        else if(str[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && checkPrecedence(st.top()) >= checkPrecedence(str[i]))
            {
                ans += st.top();
                st.pop();
            }   
            st.push(str[i]);
        }
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    
    cout << infixToPostfix(str) << endl;
    return 0;
}