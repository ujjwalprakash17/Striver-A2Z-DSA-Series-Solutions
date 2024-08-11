// merge sort algo
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int right)
{
    for(int i = left; i < right; i++)
    cout << arr[i] << " ";
}

int mergeSort(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int mid = s + (e-s) / 2;
        int left = mergeSort(arr, s, mid);
        int right = mergeSort(arr, mid + 1, e);
        merge(arr, left, right);
    }
    else return 0;
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    mergeSort(arr,0, 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    return 0;
}