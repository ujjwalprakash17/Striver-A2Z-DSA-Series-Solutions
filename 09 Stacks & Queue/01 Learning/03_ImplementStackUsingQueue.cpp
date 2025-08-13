// We have many different approaches to solve this
//  but the key insight is we need to have any one of push/pop in O(n) to achieve LIFO behaviour

#include <bits/stdc++.h>
using namespace std;

// one of the most intuitive approach is to push an element then rotate the queue
class MyStack
{ // T.C - push - O(n) and pop/top - O(1)
private:
    queue<int> q;

public:
    MyStack()
    {
    }
    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int pop()
    {
        if (q.empty())
            return -1;
        int x = q.front();
        q.pop();
        return x;
    }
    int top()
    {
        if (q.empty())
            return -1;

        return q.front();
    }
    bool Empty()
    {
        return q.empty();
    }
};

int main()
{

    return 0;
}