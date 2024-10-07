#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) 
{
    int fiveCnt = 0, tenCnt = 0, twentyCnt = 0;
    int i = 0;
    int n = bills.size();
    while(i < n){
        if(bills[i] == 5) fiveCnt++;
        else if(bills[i] == 10){
            if(fiveCnt < 1) return false;
            fiveCnt--;
            tenCnt++;
        }
        else if(bills[i] == 20)
        {
            if(fiveCnt < 3 && tenCnt < 1) return false;
            else if(tenCnt >= 1){
                tenCnt--;
                if(fiveCnt < 1) return false;
                fiveCnt--;
                twentyCnt++;
            }
            else if(fiveCnt >= 3)
            {
                fiveCnt -= 3;
                twentyCnt++;
            }
        }
        i++;
    }
    return true;
}

int main()
{
    vector<int> sample = {5,5,5,10,5,5,10,20,20,20};
     lemonadeChange(sample) ? cout << "true" << endl : cout << "false" << endl;

    
    return 0;
}