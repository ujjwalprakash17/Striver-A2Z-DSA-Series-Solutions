#include <bits/stdc++.h>
using namespace std;

//Algorithm : 
// step 1 : agar koi bhi operand hai toh push it into stack and then 
//step 2 : agar koi bhi operator mil rha hai toh stack ke 2 last element ko nikalo aur dono ko aage piche krke beech me operator add kr do aur at the same time use bracket se bhi enclose kr do. 
// that's all return kr do

string postToInfix(string &str)
{
    vector<string> st;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9'))
        {
            string s (1, str[i]);
            st.push_back(s);
        }
        else{
            int sizeOfStack = st.size();
            string temp = "(" + st[sizeOfStack - 2] + "+" + st[sizeOfStack - 1] + ")";
            st.pop_back();
            st.pop_back();
            st.push_back(temp);
        }
    }
    return st[st.size() -1];
}

int main()
{
    string sample = "ab*c+";
    cout << postToInfix(sample) << endl;

    return 0;
}