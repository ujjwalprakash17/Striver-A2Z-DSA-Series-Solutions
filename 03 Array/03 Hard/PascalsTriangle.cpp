#include <bits/stdc++.h>
using namespace std;

//approach : 
// Step 1 : create a answer matrix and fill all the matrix with the given size
// Step 2 : 
vector<vector<int>> generate(int numRows)
{
    //step 1 
    vector<vector<int>> result;
    for(int  i = 1; i <= numRows ; i++)
    {
        result.push_back(vector<int> (i, 1));
    }
    //Step 2 : start from index 2 and form a expression than will statisfy the element 
    // that
    for(int i = 2; i < numRows; i++)
    {
        for(int j = 1; j < i ; j++)
        {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    return result;
}

int main()
{

    return 0;
}