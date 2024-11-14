#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int mid, int e)
{
    vector<int> temp;
    int i = s, j = mid + 1;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= e)
        temp.push_back(arr[j++]);
    for (int k = s; k <= e; k++)
        arr[k] = temp[k - s];
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{

    return 0;
}