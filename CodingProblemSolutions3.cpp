// Problem 3: A railway system is keeping track of customer travel times between different stations. They are
// using this data to calculate the average time it takes to travel from one station to another.
// Implement a class called UndergroundSystem with the following functions:
// void checkIn(int id, string stationName, int t)
// A customer with a card ID equal to id, checks in at the station stationName at time t. A customer can only be
// checked into one place at a time.
// void checkOut(int id, string stationName, int t)
// A customer with a card ID equal to id, checks out from the station stationName at time t.
// double getAverageTime(string startStation, string endStation)
// Returns the average time it takes to travel from startStation to endStation.
// The average time is computed from all the previous traveling times from startStation to endStation that
// happened directly, meaning a check in at startStation followed by a check out from endStation. The time it takes
// to travel from startStation to endStation may be different from the time it takes to travel from endStation to
// startStation. There will be at least one customer that has traveled from startStation to endStation before
// getAverageTime is called. You may assume all calls to the checkIn and checkOut methods are consistent. If a
// customer checks in at time t1 then checks out at time t2, then t1 &lt; t2. All events happen in chronological order.
// Language you are using: ________
// Runtime Complexity of your Solution: __________
// Space Complexity of your Solution: ____________
// Write your code below (continue on back if needed):



#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
private:
    
    unordered_map<int, pair<string, int>> checkInData;    
    unordered_map<string, pair<int, int>> travelTimeData;
    
public:
    
    void checkIn(int id, string stationName, int t) {
        if(checkInData.find(id) != checkInData.end()) 
        {
            cout << "You can't go in again";
            return ;
        }
        checkInData[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {


        string startStation = checkInData[id].first;
        int startTime = checkInData[id].second;
        int travelTime = t - startTime;
        string route = startStation + "-" + stationName;
        travelTimeData[route].first += travelTime;
        travelTimeData[route].second += 1;        
        checkInData.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;
        int total = travelTimeData[route].first;
        int count = travelTimeData[route].second;
        
        return (double)total / count;
    }
};

int main() {
    UndergroundSystem us;
    return 0;
}