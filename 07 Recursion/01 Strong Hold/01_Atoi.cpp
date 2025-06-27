#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int removeWhiteSpace(string s, int index)
    {
        if (s[index] != ' ' || index >= s.length())
        {
            return index;
        }
        return removeWhiteSpace(s, index + 1);
    }

    // Helper function to convert digits recursively
    long long convertDigits(const string &s, int index, long long result, int sign)
    {
        // Base case: reached end of string or non-digit character
        if (index >= s.length() || !isdigit(s[index]))
        {
            return result * sign;
        }

        // Get current digit
        int digit = s[index] - '0';

        // Check for overflow before multiplying and adding
        // For positive numbers: result > (INT_MAX - digit) / 10
        // For negative numbers: result > (-(long long)INT_MIN - digit) / 10
        if (sign == 1)
        {
            if (result > (INT_MAX - digit) / 10)
            {
                return INT_MAX;
            }
        }
        else
        {
            if (result > (-(long long)INT_MIN - digit) / 10)
            {
                return INT_MIN;
            }
        }

        // Update result and recurse
        return convertDigits(s, index + 1, result * 10 + digit, sign);
    }

public:
    int myAtoi(string s)
    {
        int index = removeWhiteSpace(s, 0);
        if (index >= s.length())
            return 0;
        // determine sign
        int sign = 1;
        if (s[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if (s[index] == '+')
        {
            index++;
        }

        // Check if next character is a digit
        if (index >= s.length() || !isdigit(s[index]))
        {
            return 0;
        }

        // Convert digits
        return (int)convertDigits(s, index, 0, sign);
    }
};

int main()
{
    string s = "  my";
    Solution c;
    c.myAtoi(s);

    return 0;
}