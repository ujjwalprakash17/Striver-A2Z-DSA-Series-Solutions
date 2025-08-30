#include <bits/stdc++.h>
using namespace std;

// Brute Force O(n^2)
int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    if (n == 0) return 0;

    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int minHeight = heights[i];
        for (int j = i; j < n; j++) {
            minHeight = min(minHeight, heights[j]);
            int width = j - i + 1;
            int area = minHeight * width;
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}
/*
Explanation:
For each starting index i, expand the range to the right (j = i...n-1),
keeping track of the minimum height in that range. 
The rectangle area = (width of range) × (minimum bar height).
We calculate this for every possible subarray of bars and take the maximum.
This brute-force approach has O(n^2) time complexity.
*/

int main()
{

    return 0;
}