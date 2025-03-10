#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}

// Function to find closest primes in range [left, right]
vector<int> closestPrimes(int left, int right)
{
    if (right < 2)
        return {-1, -1};

    int sqrtRight = sqrt(right);
    vector<int> primes = sieve(sqrtRight);

    // Mark all numbers in range [left, right] as prime initially
    vector<bool> isPrime(right - left + 1, true);

    // Use small primes to mark multiples in [left, right]
    for (int p : primes)
    {
        int start = max(p * p, (left + p - 1) / p * p);
        for (int j = start; j <= right; j += p)
            isPrime[j - left] = false;
    }

    // Handle edge case where left = 1
    if (left == 1)
        isPrime[0] = false;

    // Find closest prime pair
    int first = -1, second = -1;
    int minDiff = INT_MAX;
    vector<int> result = {-1, -1};

    for (int i = left; i <= right; i++)
    {
        if (isPrime[i - left])
        {
            if (first == -1)
            {
                first = i;
            }
            else
            {
                second = i;
                if (second - first < minDiff)
                {
                    minDiff = second - first;
                    result = {first, second};
                }
                first = second;
            }
        }
    }

    return result;
}

int main()
{

    return 0;
}