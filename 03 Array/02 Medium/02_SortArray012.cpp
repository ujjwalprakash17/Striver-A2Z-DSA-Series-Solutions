#include <bits/stdc++.h>
using namespace std;

// void sortColors(vector<int> &nums)
// {
//     int n = nums.size();
//     int one = 0, two = 0, zero = 0;
//     // count the frequency of 0, 1 and 2
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] == 1)
//             one++;
//         else if (nums[i] == 2)
//             two++;
//         else if (nums[i] == 0)
//             zero++;
//     }
//     int k = one + two + zero;
//     for (int i = 0; i < k; i++)
//     {
//         if (zero > 0)
//         {
//             nums[i] = 0;
//             zero--;
//         }
//         else if (one > 0)
//         {
//             nums[i] = 1;
//             one--;
//         }
//         else if (two > 0)
//         {
//             nums[i] = 2;
//             two--;
//         }
//     }
// }


// Approach - 2
// Dutch National Flag Algorithm
void sortColors(vector<int> &nums)
{
    int n = nums.size() ;
    int low = 0, mid = 0, high = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++, mid++;
        }
        // case - 2
        else if (nums[mid] == 1)
            mid++;
        // case - 3
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> sample = {2, 0, 2, 1, 1, 0};
    sortColors(sample);
    for (int i = 0; i < sample.size(); i++)
    {
        cout << sample[i] << " ";
    }

    return 0;
}