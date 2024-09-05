#include <bits/stdc++.h>
using namespace std;

string prefixToPostfix(string &str) {
    vector<string> stk;
    for(int i = str.size() - 1; i >= 0; i--) {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
            stk.push_back(string(1, str[i]));  // Convert char to string
        } else {
            if (stk.size() < 2) {
                return "Error: Invalid prefix expression";  // Error handling
            }
            string temp = stk.back(); stk.pop_back();
            temp += stk.back(); stk.pop_back();
            temp += str[i];
            stk.push_back(temp);
        }
    }
    return stk.empty() ? "Error: Invalid prefix expression" : stk[0];  // Error handling
}

int main()
{

    return 0;
}