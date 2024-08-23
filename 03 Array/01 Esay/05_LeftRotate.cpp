// Left Rotate an array by one place
#include <bits/stdc++.h>
using namespace std;


//Approach - 1 : do same as stated rotate the array k times
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; //since rotating the array size times will give the same array 
    //in other words rotating array k = n times will result the original array
    while (k--)
    {
        int lastEle = nums[n - 1];
        for(int i = n - 1; i > 0 ; i--)
        {
            nums[i] = nums[i-1];
        }
        nums[0] = lastEle;
    }
}
// T.C - O(n * k) | S.C - O(1)

//Approach - 2
// step - 1 : Reverse the last k elements
// step - 2 : Reverse the remaining first n - k elements
// step - 3 : Reverse the whole array

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    //step - 1
    reverse(nums.begin() + (n - k), nums.end());
    //step - 2
    reverse(nums.begin(), nums.begin() + (n-k-1));
    //step - 3
    reverse(nums.begin(), nums.end());

}

int main()
{
    vector<int> sample = {1,2,3,4,5,6,7};
    rotate(sample, 3);
    for(int i = 0; i < sample.size() ; i++)
    cout << sample[i] << " ";
    return 0;
}