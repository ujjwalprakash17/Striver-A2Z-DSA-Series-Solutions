#include <bits/stdc++.h>
using namespace std;

double solution(double x, int n)
{
    if (n == 0)
        return 1;

    if (n & 1)
    {
        return x * solution(x * x, n / 2);
    }

    return solution(x * x, n / 2);
}

double myPow(double x, int n)
{
    if (n == 0 || x == 1)
        return 1;
    if (n < 0)
    {
        x = 1 / x;
        long long val = n;
        return solution(x, n);
    }
    return solution(x, n);
}

int main()
{

    return 0;
}