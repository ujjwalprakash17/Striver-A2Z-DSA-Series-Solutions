// Second Largest Element in an Array without sorting
#include <bits/stdc++.h>
using namespace std;
// Approach :
    // same concept as finding largest element, but we will 
    // use a tail pointer, 
    // case - 1
    // so whenever the maxi will change 
    // the tail value will be the maxi value first, and then 
    // the maxi value will be updated 
    // case - 2
    // a value greater than tail but lesser than maxi, so 
    // initialise tail value first

// Code :   
int print2largest(vector<int> &arr)
{
    // Code Here
    int tail = INT_MIN, maxi = arr[0];
    for(int i = 0; i < arr.size() ; i++)
    {
        if(arr[i] > maxi) // case - 1
        {
            tail = maxi;
            maxi = arr[i];
        }
        else if(arr[i] < maxi && arr[i] > tail) // case - 2 
        tail = arr[i];
    }
    return tail;
}

int main()
{

    return 0;
}