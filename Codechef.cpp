#include <bits/stdc++.h>
using namespace std;

int solution(int x, int y, int k)
{
    if (k != 0 && abs(x - y) % k != 0)
        return -1;
    int diff = abs(x - y);
    int ans = (diff - k) / 2;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        cout << solution(x, y, k) << endl;
    }

    return 0;
}