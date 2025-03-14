// Problem Statement : 
// A 2D List/Array of transactions with each transaction record having a transaction ID (integer), credit card
// ID (integer, transaction amount (double), city (string), and time in minutes (integer). You can assume all
// transactions happen on the same day.

#include <bits/stdc++.h>
#include<tuple>
using namespace std;

// define a tuple 
using Transaction = tuple<int, int, double, string, int>; 

vector<int> fraudulentTransactions(vector<Transaction> &transactions)
{
    unordered_map<int, vector<tuple<int, string, int>>> transactionHistory;
    vector<int> ans;
    for(auto &transaction : transactions)
    {
        int tId = get<0>(transaction);
        int cardId = get<1>(transaction);
        double amount = get<2>(transaction);
        string city = get<3>(transaction);
        int time = get<4>(transaction);
        
        bool isFraudlant = false;

        if(amount >= 10000){
            isFraudlant = true;
        }
        else if(transactionHistory.find(cardId) != transactionHistory.end())
        {
            for(auto & prevTransation : transactionHistory[cardId])
            {
                int prevtId = get<0>(prevTransation);
                string prevCity = get<1>(prevTransation);
                int prevtime = get<2>(prevTransation);

                if(time-prevtime <= 30 && city != prevCity)
                {
                    isFraudlant = true;
                    break;
                }
            }
        }

        if(isFraudlant){
            ans.push_back(tId);
        }

        transactionHistory[cardId].push_back({tId, city, time});
    }
    return ans;
}


int main() {
    vector<Transaction> sample = {
        {1, 1000, 500.00, "Vadodara", 0},
        {2, 1000, 500.00, "Mumbai", 5},
        {3, 1001, 500.00, "Mumbai", 10},
        {4, 1001, 10000.00, "Mumbai", 10}
    };

    vector<int> result = fraudulentTransactions(sample);
    for (int id : result) {
        cout << id << " ";
    }
    cout << endl;
    return 0;
}

// Time Complexity - O(n^2);

// Space Complexity : O(n);