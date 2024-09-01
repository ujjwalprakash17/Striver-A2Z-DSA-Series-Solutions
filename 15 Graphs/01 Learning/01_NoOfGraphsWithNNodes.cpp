#include <bits/stdc++.h>
using namespace std;

long long count(int n)
{
    // your code here
    long long value = ((long long) n * (long long)(n-1) ) / 2;
    return pow(2, value);
}

int main()
{

    return 0;
}