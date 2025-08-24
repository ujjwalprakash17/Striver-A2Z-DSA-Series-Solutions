#include <bits/stdc++.h>
using namespace std;

// intuition :
// think like this ki hame har ek index se yeh dekhna hai ki uske left me aur right me koi bada hai usse
// then only you will be able to store water otherwise you cannot
//
// Detailed intuition:
// 1. Har index par water trap hone ke liye, us index ke left me aur right me dono taraf
//    koi na koi higher wall honi chahiye
// 2. Agar left ya right me se koi bhi side me higher wall nahi hai, toh water flow ho jayega
// 3. Jo water trap hoga wo depend karta hai minimum height par jo left max aur right max me se hai
//    kyunki water us lowest boundary tak hi ruk sakta hai
// 4. Formula: water at index i = min(leftMax, rightMax) - height[i]
//    (sirf tab jab height[i] < min(leftMax, rightMax) ho)
//
// Example: [3,0,2,0,4]
// Index 1 (height=0): leftMax=3, rightMax=4 -> water = min(3,4) - 0 = 3
// Index 3 (height=0): leftMax=3, rightMax=4 -> water = min(3,4) - 0 = 3
// Total = 6

void computePrefixLeft(vector<int> &height, vector<int> &prefixLeft)
{
    prefixLeft[0] = height[0];
    for (int i = 1; i < height.size(); i++)
    {
        prefixLeft[i] = max(prefixLeft[i - 1], height[i]);
    }
}

void computeSuffixRight(vector<int> &height, vector<int> &suffixRight) // FIXED: added & for reference
{
    int n = height.size();
    suffixRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixRight[i] = max(suffixRight[i + 1], height[i]);
    }
}

int trap(vector<int> &height)
{
    int n = height.size();
    if (n <= 2)
        return 0; // Optional: handle edge cases

    int total = 0;
    vector<int> prefixLeft(n);
    vector<int> suffixRight(n);

    computePrefixLeft(height, prefixLeft);
    computeSuffixRight(height, suffixRight);

    for (int i = 0; i < n; i++)
    {
        int leftMax = prefixLeft[i];
        int rightMax = suffixRight[i];
        if (height[i] < leftMax && height[i] < rightMax)
            total += min(leftMax, rightMax) - height[i];
    }
    return total;
}

// Optimization : we are optimising the space using the below intuition
//  Key Insight: Agar hum jante hain ki left_max < right_max hai current moment me, toh:

// min(left_max, right_max) = left_max
// Matlab right side kitna bhi bada ho, water level left_max se determine hoga
// So hum safely left position process kar sakte hain

int trap(vector<int> &height)
{
    int n = height.size();
    int total, leftMax, rightMax;
    leftMax = rightMax = total = 0;
    int left = 0;
    int right = n - 1;
    while (left < right)
    {

        if (height[left] <= height[right])
        {
            if (leftMax > height[left])
            {
                total += leftMax - height[left];
            }
            else
            {
                leftMax = height[left];
            }
            left++;
        }
        else
        {
            if (rightMax > height[right])
            {
                total += rightMax - height[right];
            }
            else
            {
                rightMax = height[right];
            }
            right--;
        }
    }
    return total;
}

int main()
{
    // Test case
    vector<int> height = {3, 0, 2, 0, 4};
    cout << "Trapped water: " << trap(height) << endl;

    return 0;
}