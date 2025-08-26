#include <bits/stdc++.h>
using namespace std;

//APPROACH : 
//since we can just remove the k digits from left of str, but we have an edge in the problem that we can remove any k digits, so the idea is 
//why not remove the bigger digits first : Stack + Greedy Approach
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        
        for (char digit : num) {
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        
        // Remove remaining digits if k > 0
        while (k > 0) {
            result.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int start = result.find_first_not_of('0'); //this will give us an starting index where a non zero is located
        result = (start == string::npos) ? "0" : result.substr(start);
        
        return result.empty() ? "0" : result;
    }
};
int main()
{

    return 0;
}