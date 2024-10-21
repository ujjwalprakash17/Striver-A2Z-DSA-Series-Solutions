#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> sample = {3,2,1,4,5};
    next_permutation(sample.begin(), sample.end());
    for(int i : sample)
    cout << i << " ";

    return 0;
}