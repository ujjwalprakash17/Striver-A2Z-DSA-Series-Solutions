#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
private:
    std::stack<int> input;  // Stack for push operations
    std::stack<int> output; // Stack for pop/peek operations

    // Helper function to transfer elements from input to output
    void transfer()
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
    }

public:
    MyQueue()
    {
        // Constructor - stacks are automatically initialized
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        // If output stack is empty, transfer from input
        if (output.empty())
        {
            transfer();
        }

        int front = output.top();
        output.pop();
        return front;
    }

    int peek()
    {
        // If output stack is empty, transfer from input
        if (output.empty())
        {
            transfer();
        }

        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{

    return 0;
}