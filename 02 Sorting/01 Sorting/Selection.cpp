#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < arr.size(); j++)
        {
            if(arr[j] < arr[minIndex])
            minIndex = j;
            // mini = min(mini, arr[j]);
        }
        swap(arr[i], arr[minIndex]);;
    }
    for(int i : arr)
    cout << i << " ";
}

int main()
{
    vector<int> arr= {4, 1, 3, 9 , 7};
    selectionSort(arr);
    
    return 0;
}