#include <bits/stdc++.h>
using namespace std;
class MinStack
{
private:
    vector<pair<int, int>> stk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stk.empty())
        {
            stk.push_back({val, val});
            return ;
        }
        int minEle = stk.back().second;

        stk.push_back({val, min(minEle, val)});
    }

    void pop()
    {
        if (stk.empty())
            return;
        stk.pop_back();
    }

    int top()
    {
        auto top = stk.back();
        return top.first;
    }

    int getMin()
    {
        auto top = stk.back();
        return top.second;
    }
};
int main()
{
    
    return 0;
}