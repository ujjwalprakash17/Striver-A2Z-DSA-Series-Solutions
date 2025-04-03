#include <bits/stdc++.h>
using namespace std;

// 1,2,3,4,5
//7,1,5,3,6,4
//7,6,4,3,1

int maxProfit(vector<int> &prices)
{
    int totalProfit = 0;
    int n = prices.size();
    int buyPrice = prices[0];
    for (int i = 1; i < n ; i++)
    {
        if (prices[i] > buyPrice)
        {
            totalProfit += (prices[i] - buyPrice);
        }
        buyPrice = prices[i];
    }
    return totalProfit;
}

int main()
{
    vector<int> sample = {1,2,3,4,5};
    cout << maxProfit(sample) << "\n";
    return 0;
}