#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int x, vector<int> &quantities, int n)
{
    int store_count = 0;
    for (int q : quantities)
    {
        store_count += (q + x - 1) / x; // Equivalent to ceiling(q / x)
    }
    return store_count <= n;
}

int minimizedMaximum(int n, vector<int> &quantities)
{
    int s = 0, e = *max_element(quantities.begin(), quantities.end());
    int ans = e;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isFeasible(mid, quantities, n))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<int> sample = {11, 6};
    cout << minimizedMaximum(n, sample) << endl;

    return 0;
}