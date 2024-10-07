// the concept of this question is to use two stacks, 
// one to store '(' and one to store '*' 
// and handle the edge cases such that 

// try to perform operations on leftparen stack, to pop, if not available then use star stack

// also return leftparen stack.size() simple 
#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{
    stack<char> st;
    int cnt = 0;
    //first we will push
    for(int i = 0 ; i< s.size() ; i++)
    {
        // case 1 if s[i] == '('
        if(s[i] == '(')
        {
            st.push('(');
        }
        else if(s[i] == '*') cnt++;
        else if(s[i] == ')') {
            if(st.empty() && cnt == 0)
            return false;
            else if(st.empty () && cnt > 0)
            cnt--;
            else if(st.top() == '(')
            st.pop();
        }
    }
    //then 
    for(int i = 0; i < cnt; i++)
    {
        if(st.empty()) break;
        else if(st.top() == '(')
        st.pop();
    }
    if(st.empty()) return true;
    return false;
}

int main()
{
    string s = ")*";
    checkValidString(s) ? cout<<  "true" : cout << "false" << endl;

    return 0;
}