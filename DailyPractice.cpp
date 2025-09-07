#include <bits/stdc++.h>
using namespace std;
vector<int> sumZero(int n)
{
    vector<int> ans;
    if (!(n & 1))
        n += 1;
    int start = (-1) * n / 2;
    int end = ((-1) * n / 2) + n;
    for (int i = start; i < end; i++)
    {
        if (!(n & 1) && i == 0)
        {
            continue;
        }
        ans.push_back(i);
    }
    return ans;
}
int main()
{
    sumZero(5);

    return 0;
}