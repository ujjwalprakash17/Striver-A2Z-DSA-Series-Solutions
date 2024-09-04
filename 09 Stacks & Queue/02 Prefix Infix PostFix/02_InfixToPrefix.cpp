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
        return 0;
    }
}
string infixToPostFix(string &str)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >='0' && str[i] <= '9'))
            ans += str[i];
        else if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && checkPrecedence(st.top()) > checkPrecedence(str[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string infixString = "(A-B/C)*(A/K-L)";
    // step 1 : Reverse the infixString
    reverse(infixString.begin(), infixString.end());
    // step 2 : check and conver ( to ) and ) to (
    for (int i = 0; i < infixString.size(); i++)
    {
        if (infixString[i] == ')')
            infixString[i] = '(';
        else if (infixString[i] == '(')
            infixString[i] = ')';
    }
    // step 2 : convert infix to postfix but controlled
    string postfix = infixToPostFix(infixString);
    // step 3 :
    reverse(postfix.begin(), postfix.end());
    cout << postfix << endl;

    return 0;
}