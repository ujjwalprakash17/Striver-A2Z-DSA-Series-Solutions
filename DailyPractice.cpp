#include <bits/stdc++.h>
using namespace std;

// BruteForce solution :
// check each row, each column, and each boxes
bool isValidSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    bool check[n];
    // checking for rows only
    for (int i = 0; i < n; i++)
    {
        fill(check, check + 9, false);
        for (int j = 0; j < n; j++)
        {
            char val = board[i][j];
            if (val != '.')
            {
                int idx = (val - '0') - 1;
                if (check[idx] != false)
                    return false;
                check[idx] = true;
            }
        }
        // checking for columns only
        for (int i = 0; i < n; i++)
        {
            fill(check, check + 9, false);
            for (int j = 0; j < n; j++)
            {
                char val = board[j][i];
                if (val != '.')
                {
                    int idx = (val - '0') - 1;
                    if (check[idx] != false)
                        return false;
                    check[idx] = true;
                }
            }
            // checking for boxes only
            for (int boxRow = 0; boxRow < 9; boxRow += 3)
            {
                for (int boxCol = 0; boxCol < 9; boxCol += 3)
                {
                    fill(check, check + 9, false);
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            char val = board[boxRow + i][boxCol + j];
                            if (val != '.')
                            {
                                int idx = (val - '0') - 1;
                                if (check[idx])
                                    return false;
                                check[idx] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

// OPTIMAL APPROACH : flip perspective
// thought process : see as you can see we are seeing / checking 3 different infos (ek row me hai ya nhi, ek col me hai ya nhi aur tisra ki same box me hai ya nhi)
// chuki in 3 infos ko agar me 1 go me store krane lage toh hamara kaam ho jayega
// kaise ? hamne suppose 2, 5 pr hain, aur element[2][5] = 7 hai,
// agar hamne ye store kr liya ki
//  1. row 2 pr 7 hai
//  2. col 5 pr 7 hai
//  3. most important observation was : 2 / 3, 5 / 3 = [0, 1] pr 7 hai
// since ek box ke kisi bhi index (9 me se koi bhi) ko agar 3 se divide kiya toh value same milegi
// and keep checking it then we will get our required value
bool isValidSudoku(vector<vector<char>> &board)
{
    set<string> check;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char tempChar = board[i][j];
            if (tempChar == '.')
                continue; // skip empty cells

            string tempRow = "row" + to_string(i) + "has" + string(1, tempChar);
            string tempCol = "col" + to_string(j) + "has" + string(1, tempChar);
            string boxCheck = "box" + to_string(i / 3) + "_" + to_string(j / 3) + "has" + string(1, tempChar);

            if (check.find(tempRow) != check.end() ||
                check.find(tempCol) != check.end() ||
                check.find(boxCheck) != check.end())
                return false;

            check.insert(tempRow);
            check.insert(tempCol);
            check.insert(boxCheck);
        }
    }
    return true;
}
// more optimize format of this is :
bool isValidSudoku(vector<vector<char>> &board)
{
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[3][3][9] = {false};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;

            int num = board[i][j] - '1'; // 0..8
            if (row[i][num] || col[j][num] || box[i / 3][j / 3][num])
                return false;

            row[i][num] = col[j][num] = box[i / 3][j / 3][num] = true;
        }
    }
    return true;
}

int main()
{

    return 0;
}