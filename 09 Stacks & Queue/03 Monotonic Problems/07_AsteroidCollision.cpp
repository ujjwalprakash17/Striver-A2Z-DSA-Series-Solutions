#include <bits/stdc++.h>
using namespace std;
//Thought process: 
//we will need a stack to store +ves first and whenever we will encounter any -ves then we will try to check the stack top and then compare it
//MY doubts : 
//what if we got -ves first, then in that case we will simply store the -ves in the array

vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size();
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        int currEle = asteroids[i];
        if (currEle > 0)
        {
            stk.push(currEle);
        }
        else if (!stk.empty() && currEle < 0)
        {
            while (!stk.empty() && stk.top() > 0 && stk.top() < abs(currEle))
            {
                stk.pop();
            }

            if (stk.empty() || stk.top() < 0)
            {
                stk.push(currEle);
            }
            else if (stk.top() == abs(currEle))
            {
                stk.pop(); // both destroy
            }
        }
    }
    // copy the elements of stack into vector and reverse the vector and return
    vector<int> ans;
    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}