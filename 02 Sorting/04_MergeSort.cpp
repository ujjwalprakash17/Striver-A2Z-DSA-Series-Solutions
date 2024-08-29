// merge sort algo
#include <bits/stdc++.h>
using namespace std;

// write here we are writing merge function

void merge(vector<int> &arr, int l, int m, int r)
{
    std::vector<int> temp;
    int i = l;
    int j = m + 1;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = l; k <= r; k++)
    {
        arr[k] = temp[k - l];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{

    // This means that there is atleast one element
    if (l < r)
    {
        // Finding the mid point
        int m = (l + r) / 2;

        // Sorting the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merging the two sorted arrays
        merge(arr, l, m, r);
    }
}

int main()
{
    vector<int> sample = {4, 1, 3, 9, 7};
    mergeSort(sample, 0, sample.size() - 1);
    return 0;
}