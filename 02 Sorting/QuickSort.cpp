#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        // greater dundhenge
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        // smaller dhundenge
        while (arr[j] > pivot && j > low)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    vector<int> arr = {4, 1, 3, 9, 7};
    quickSort(arr, 0, 4);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}