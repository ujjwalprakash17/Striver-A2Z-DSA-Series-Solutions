#include <bits/stdc++.h>
using namespace std;

// instead of storing characters we will be storing indices, this will help us to decide which is previous and which is after

// T.C - O(n) , S.C - O(n)
bool checkValidString(string s)
{
    stack<int> open, star;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            open.push(i);
        }
        else if (s[i] == '*')
        {
            star.push(i);
        }
        else
        { // ')'
            if (!open.empty())
            {
                open.pop();
            }
            else if (!star.empty())
            {
                star.pop();
            }
            else
            {
                return false; // no match available
            }
        }
    }

    // Match remaining '(' with later '*'
    while (!open.empty() && !star.empty())
    {
        if (open.top() < star.top())
        {
            open.pop();
            star.pop();
        }
        else
        {
            return false; // '(' occurs after '*' → cannot match
        }
    }

    return open.empty();
}

int main()
{

    return 0;
}