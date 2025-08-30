#include <bits/stdc++.h>
using namespace std;

// Brute Force O(n^2)
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    if (n == 0)
        return 0;

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int minHeight = heights[i];
        for (int j = i; j < n; j++)
        {
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

vector<int> findPrevMinInd(vector<int> &heights)
{
    int n = heights.size();
    vector<int> arr(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && heights[stk.top()] > heights[i])
            stk.pop();
        if (!stk.empty())
            arr[i] = stk.top();
        stk.push(i);
    }
    return arr;
}

vector<int> findNextMinInd(vector<int> &heights)
{
    int n = heights.size();
    vector<int> arr(n, n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();
        if (!stk.empty())
            arr[i] = stk.top();
        stk.push(i);
    }
    return arr;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    if (n == 0)
        return 0;
    int maxArea = 0;
    vector<int> prevMin = findPrevMinInd(heights);
    vector<int> nextMin = findNextMinInd(heights);
    for (int i = 0; i < n; i++)
    {
        int prevInd = prevMin[i];
        int nextInd = nextMin[i];
        int area = (nextInd - prevInd - 1) * heights[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

//more readable yet more concise format
int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> stk;
    vector<int> left(n), right(n);

    // Find previous smaller elements
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
        left[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }

    // Clear stack to reuse
    while (!stk.empty()) stk.pop();

    // Find next smaller elements
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
        right[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }

    // Compute max area
    int maxArea = 0;
    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));

    return maxArea;
}


int main()
{

    return 0;
}