#include <bits/stdc++.h>
using namespace std;

int factOfN(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

int findPrimePermutations(int n)
{
    // Write your code here.
    vector<int> primeVal(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            primeVal[j] = true;
        }
    }
    int primeNumberCnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!primeVal[i])
            primeNumberCnt++;
    }
    int ans = factOfN(primeNumberCnt);
    return ans;
}

int main()
{
    int n = 3;
    cout << findPrimePermutations(4);
    
    return 0;
}