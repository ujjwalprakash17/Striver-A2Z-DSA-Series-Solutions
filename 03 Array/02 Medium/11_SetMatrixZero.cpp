#include <bits/stdc++.h>
using namespace std;

//Approach : 
// 1. check for the first row and col if they contain 0 or not
// 2. loop from 1 -> n and 1 -> m and check if any of them contains 0 then set both row and column to 0 
// 3. at last check and set the first row and column if they contain 0;


vector<vector<int>> findGoodMatrix(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    // Check if the first row has zero
    for (int j = 0; j < m; ++j)
    {
        if (arr[0][j] == 0)
        {
            firstRowHasZero = true;
            break;
        }
    }

    // Check if the first column has zero
    for (int i = 0; i < n; ++i)
    {
        if (arr[i][0] == 0)
        {
            firstColHasZero = true;
            break;
        }
    }

    // Mark zeros on first row and column
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (arr[i][j] == 0)
            {
                arr[0][j] = 0;
                arr[i][0] = 0;
            }
        }
    }

    // Use marks to set elements
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (arr[0][j] == 0 || arr[i][0] == 0)
            {
                arr[i][j] = 0;
            }
        }
    }

    // Set the first row to zero if needed
    if (firstRowHasZero)
    {
        for (int j = 0; j < m; ++j)
        {
            arr[0][j] = 0;
        }
    }

    // Set the first column to zero if needed
    if (firstColHasZero)
    {
        for (int i = 0; i < n; ++i)
        {
            arr[i][0] = 0;
        }
    }

    return arr;
}

int main()
{

    return 0;
}