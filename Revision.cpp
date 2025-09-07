#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    int n = val.size();
    double maxValbyWt = 0.0;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; i++)
    {
        items.push_back({val[i], wt[i]});
    }
    sort(items.begin(), items.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             double valbyWt1 = (double)a.first / (double)a.second;
            double valbyWt2 = (double)b.first / (double)b.second;
            return valbyWt1 > valbyWt2; });
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;
        if (items[i].second >= capacity)
        {
            ans += capacity * (double)(items[i].first / (double)items[i].second);
            capacity -= capacity;
        }
        else
        {
            ans += items[i].first;
            capacity -= items[i].second;
        }
    }
    return ans;
}
int main()
{
    vector<int> val = {8, 2, 10, 1, 9, 7, 2, 6, 4, 9};
    vector<int> wt = {10, 1, 7, 7, 5, 1, 8, 6, 8, 7};
    cout << fractionalKnapsack(val, wt, 21);

    return 0;
}