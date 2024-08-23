#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solution(int mySum, int ind, int n , int arr[], int givenSum)
{
    //base case 
    if(ind == n)
    {
        if(mySum == givenSum) return 1;
        else return 0;
    }
    int left = solution(mySum + arr[ind], ind + 1, n , arr, givenSum);
    int right = solution(mySum, ind + 1, n , arr, givenSum);
    return left + right;
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    return solution(0, 0, n, arr, sum);
}

int main()
{

    return 0;
}