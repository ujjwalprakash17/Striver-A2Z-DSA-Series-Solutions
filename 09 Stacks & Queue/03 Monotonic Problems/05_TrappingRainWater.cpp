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

/* 
TWO POINTER OPTIMIZATION - INTUITION:

Key Insight: Hame sirf min(leftMax, rightMax) chahiye har index ke liye!

Think karo aise:
1. Current approach me hum pura leftMax[] aur rightMax[] array bana rahe hain
2. Lekin actually hame sirf current position ka leftMax aur rightMax chahiye
3. Agar left_max < right_max hai, toh water level left_max se determine hoga
   kyunki min(left_max, right_max) = left_max
4. Similarly, agar right_max < left_max hai, toh right_max determine karega

Main realization:
- Agar left pointer par left_max smaller hai, toh us position ka water level 
  left_max se hi decide ho jayega, right_max kitna bhi bada ho
- Kyunki final answer = min(left_max, right_max) - height[i]
- Aur hum already jante hain ki left_max < right_max (at that moment)

Example walkthrough:
[0,1,0,2,1,0,1,3,2,1,2,1]
 L                       R
left_max=0, right_max=1

Since left_max < right_max, left position ka water = left_max - height[L] = 0-0 = 0
Ab left++ kar sakte hain safely!

Space: O(n) -> O(1)
Time: O(n) remains same
*/

// Optimized O(1) space approach using two pointers
int trapOptimized(vector<int> &height)
{
    int n = height.size();
    if (n <= 2) return 0;
    
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water = 0;
    
    while (left < right) {
        // Update current maximums
        left_max = max(left_max, height[left]);
        right_max = max(right_max, height[right]);
        
        // Key insight: Jo side me smaller max hai, waha water calculate kar sakte hain
        if (left_max < right_max) {
            // Left side determine kar raha hai water level
            // Kyunki min(left_max, right_max) = left_max
            water += left_max - height[left];
            left++;
        } else {
            // Right side determine kar raha hai water level  
            // Kyunki min(left_max, right_max) = right_max
            water += right_max - height[right];
            right--;
        }
    }
    
    return water;
}

// Step by step visualization function
void visualizeTwoPointer(vector<int> &height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int step = 1;
    
    cout << "Initial array: ";
    for (int x : height) cout << x << " ";
    cout << "\n\n";
    
    while (left < right) {
        left_max = max(left_max, height[left]);
        right_max = max(right_max, height[right]);
        
        cout << "Step " << step++ << ":\n";
        cout << "left=" << left << ", right=" << right << "\n";
        cout << "left_max=" << left_max << ", right_max=" << right_max << "\n";
        
        if (left_max < right_max) {
            int water = left_max - height[left];
            cout << "left_max < right_max, so process left\n";
            cout << "Water at index " << left << " = " << left_max << " - " << height[left] << " = " << water << "\n";
            left++;
        } else {
            int water = right_max - height[right];
            cout << "right_max <= left_max, so process right\n"; 
            cout << "Water at index " << right << " = " << right_max << " - " << height[right] << " = " << water << "\n";
            right--;
        }
        cout << "\n";
    }
}
