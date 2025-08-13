#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        while (q1.size() > 1)
        {
            int top = q1.front();
            q2.push(top);
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        swap(q1, q2);
        return x;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        while (q1.size() > 1)
        {
            int top = q1.front();
            q2.push(top);
            q1.pop();
        }
        int x = q1.front();
        return x;
    }

    bool empty()
    {
        if (q1.size() == 0 && q2.size() == 0)
            return true;
        else
            return false;
    }
};

int main()
{

    return 0;
}