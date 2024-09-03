#include <bits/stdc++.h>
using namespace std;
class MinStack {
private:
    vector<long long> st1;
    vector<long long> st2;

public:
    MinStack() {
        // Initialize mini to INT_MAX in the constructor
        mini = INT_MAX;
    }

    int mini;

    void push(int val) {
        st1.push_back(val);
        mini = min(mini, val);
        st2.push_back(mini);
    }

    void pop() {
        st1.pop_back();
        st2.pop_back();
        // Update mini after popping
        if (!st2.empty()) {
            mini = st2.back();
        } else {
            mini = INT_MAX;
        }
    }

    int top() {
        return st1.back();
    }

    int getMin() {
        return st2.back();
    }
};

int main()
{
    
    return 0;
}