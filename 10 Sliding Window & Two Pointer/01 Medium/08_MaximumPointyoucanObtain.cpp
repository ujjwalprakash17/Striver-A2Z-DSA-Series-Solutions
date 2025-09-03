#include <bits/stdc++.h>
using namespace std;

// since we need to find out the all the possibilities, because choosing an element either from left or right greedily may throw wrong answer, because it won't see the future possibilities of an upcoming number
// so we need to try out all the possibilities:
// objective : choose element either from left or right end where the sum of k choosen element will be maximum

// Bruteforce solution : choose 0 from left , k from right
// Bruteforce solution : choose 1 from left , k - 1 from right
// Bruteforce solution : choose 2 from left , k - 2 from right
// Bruteforce solution : choose 3 from left , k - 3 from right
// Bruteforce solution : choose k from left , 0 from right

// and we will return the maximum of all of this

// OPTIMAL APPROACH :
//  we can flip our perspective and think like this
// instead of taking element from both end, why don't we find middle subarray where sum of n - k elements will be minimum,
// once we found that
// maximum from either end will be = totalsum - minimum of n - k element from middle

// objective comes down to : find subarray where sum of element is minimum and length of subarray is n - k
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int miniMumSum = INT_MAX;
    int sum = 0;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        sum += cardPoints[right];
        if (right - left + 1 > n - k)
        {
            sum -= cardPoints[left];
            left++;
        }
        if (right - left + 1 == n - k)
            miniMumSum = min(miniMumSum, sum);
    }
    int totalSum = 0;
    for (int ele : cardPoints)
    {
        totalSum += ele;
    }
    return totalSum - miniMumSum;
}

int main()
{
    vector<int> sample = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << maxScore(sample, k) << endl;

    return 0;
}