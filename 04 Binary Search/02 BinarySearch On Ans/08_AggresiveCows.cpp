#include <bits/stdc++.h>
using namespace std;

//Approach :
// 1. will try to place cows and distance between the consequtive cows distance should be max
// 2. you know how binary search works 
// 3. check function : 
    // you have placed the first cow at first stall which is index 0
    // you start placing cows and checking the distance between the cows should be at least the distance value
    //if the distance value is enough you place the cow and increment the no of cows placed 
    // if all the cows place at the required distances then you have return true or return false


bool check(int distance, vector<int> &stalls, int k){
    int cowsCnt = 1;
    int lastCow = stalls[0];
    for(int i = 0; i < stalls.size(); i++){
        if(stalls[i] - lastCow >= distance){
            cowsCnt++;
            lastCow = stalls[i];
        }
        if(cowsCnt >= k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    // Write your code here
    //sort the stalls first to find  the consequtive distance
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int s = 1, e = stalls[n-1];
    while(s <= e){
        int minDistance = s + (e-s)/ 2;
        if(check(minDistance, stalls, k)){
            s = minDistance + 1;
        }else{
            e = minDistance - 1;
        }
    }
    return e;
}

int main() {
    
    return 0;
}