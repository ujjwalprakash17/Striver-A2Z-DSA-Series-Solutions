#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    int n = s.size();
    vector<int> freq(n + 2, 0);
    for (auto it : shifts)
    {
        int start = it[0];
        int end = it[1];
        int direc = it[2];
        if (direc == 1)
        {
            freq[start]++;
            freq[end + 1]--;
        }
        else
        {
            freq[start]--;
            freq[end + 1]++;
        }
    }
    int shift = 0;
    for (int i = 0; i < n; ++i)
    {
        shift += freq[i];
        shift %= 26;                                 // Because there are 26 letters in the alphabet
        s[i] = (s[i] - 'a' + shift + 26) % 26 + 'a'; // Ensuring the result is within 'a' to 'z' }
    }
    return s;
}

int main()
{
    string s = "dztz";
    vector<vector<int>> shifts = {{0, 0, 0}, {1, 1, 1}};
    s = shiftingLetters(s, shifts);
    cout << s << "\n";
    // int val = (124 % 97) % 26;
    // cout << val << "\n";
    return 0;
}