#include <bits/stdc++.h>
#define ll long long
#define e endl
#define sort(xyz) sort(xyz.begin(), xyz.end())
using namespace std;
const int MOD = 1e9 + 7;

int solution(int n)
{
    int oddCnt = 0;
    int evenCnt = 0;
    n & 1 ? oddCnt++ : evenCnt++;
    for (int i = 1; i <= n / 2; i++)
    {
        if(i & 1) oddCnt++;
        else evenCnt++;
    }
    if(evenCnt > oddCnt) return 1;
    else if(oddCnt > evenCnt) return -1;
    return 0;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solution(n) << endl;
    }

    return 0;
}