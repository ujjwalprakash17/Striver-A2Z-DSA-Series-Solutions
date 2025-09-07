#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int n = bills.size();
    int coinsCount[] = {0, 0, 0};
    for (int bill : bills)
    {
        if (bill == 5)
        {
            coinsCount[0]++;
        }
        else if (bill == 10)
        {
            coinsCount[0]--;
            coinsCount[1]++;
        }
        else if (bill == 20)
        {
            // case 1 : if 10 is present
            if (coinsCount[1] > 0)
            {
                coinsCount[1]--;
                coinsCount[0]--;
            }
            else
            {
                coinsCount[0] -= 3;
            }
            coinsCount[2]++;
        }

        if (coinsCount[0] < 0 || coinsCount[1] < 0 || coinsCount[2] < 0)
            return false;
    }
    return true;
}

int main()
{
    vector<int> sample = {5, 5, 5, 10, 5, 5, 10, 20, 20, 20};
    lemonadeChange(sample) ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}