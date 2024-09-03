#include <bits/stdc++.h>
using namespace std;

string infixToPostfix(string s) {
    string ans = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '(') {
            if (st.empty() || s[i] == '(') {
                st.push(s[i]);
            } else {
                if (s[i] == '+' || s[i] == '-') {
                    while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '^' || (s[i] == '+' && st.top() == '-') || (st.top() == '-' && s[i] == '+'))) {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                } else if (s[i] == '*' || s[i] == '/') {
                    while (!st.empty() && st.top() == '^') {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                } else {
                    st.push(s[i]);
                }
            }
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else {
            ans += s[i];
        }
    }
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


int main()
{
    
    return 0;
}