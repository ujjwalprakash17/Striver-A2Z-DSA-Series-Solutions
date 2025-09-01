#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
private:
    stack<pair<int, int>> stk;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int cnt = 1; // today's price counts at least for 1
        while (!stk.empty() && stk.top().first <= price)
        {
            // if the top price is <= current, merge its span into cnt
            cnt += stk.top().second;
            stk.pop();
        }
        // push current price with its accumulated span
        stk.push({price, cnt});
        return cnt;
    }
};

int main()
{
    StockSpanner stp;
    cout << stp.next(100) << "\n";
    cout << stp.next(80) << "\n";
    cout << stp.next(60) << "\n";
    cout << stp.next(70) << "\n";
    cout << stp.next(60) << "\n";
    cout << stp.next(75) << "\n";

    return 0;
}