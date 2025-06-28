#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;

    long long powerFn(long long base, long long exp)
    {
        if (exp == 0)
            return 1;
        if (exp & 1)
        {
            return (base * powerFn((base * base) % mod, exp / 2)) % mod;
        }
        return powerFn((base * base) % mod, exp / 2);
    }

    int countGoodNumbers(long long n)
    {
        // Even positions (0, 2, 4, ...) can have digits 0, 2, 4, 6, 8 (5 choices)
        // Odd positions (1, 3, 5, ...) can have digits 2, 3, 5, 7 (4 choices)

        long long evenPositions = (n + 1) / 2; // Number of even positions
        long long oddPositions = n / 2;        // Number of odd positions

        return (powerFn(5, evenPositions) * powerFn(4, oddPositions)) % mod;
    }
};

int main()
{

    return 0;
}