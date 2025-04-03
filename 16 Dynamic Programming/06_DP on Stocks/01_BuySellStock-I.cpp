#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = prices[0];
    int maxProfit = 0;
    for(int i = 1 ; i < prices.size() ; i++){
        maxProfit = max(maxProfit, prices[i]-buy);
        buy = min(prices[i], buy);
    }
    return maxProfit;
}

int main() {
    
    return 0;
}