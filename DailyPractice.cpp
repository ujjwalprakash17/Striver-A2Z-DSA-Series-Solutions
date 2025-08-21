#include <bits/stdc++.h>
using namespace std;




int main()
{

    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        cout << "Before push: size=" << v.size()
             << ", capacity=" << v.capacity() << endl;
        v.push_back(i);
        cout << "After push: size=" << v.size()
             << ", capacity=" << v.capacity() << endl;
    }
    return 0;
}