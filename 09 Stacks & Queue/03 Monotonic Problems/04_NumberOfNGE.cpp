#include <bits/stdc++.h>
using namespace std;



int main()
{
    vector<int> sample = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices = {0, 5};
    vector<int> result = count_NGE(sample.size(), sample, 2, indices);
    //  = count_NGE();
    for (int i = 0; i < sample.size(); i++)
        cout << result[i] << " ";
    return 0;
}