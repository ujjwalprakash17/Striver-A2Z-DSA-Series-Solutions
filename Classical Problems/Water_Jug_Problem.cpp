#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Custom hash function for pair
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return p.first * 10000 + p.second;
    }
};

int minSteps(int M, int N, int W) {
    // Check if W is divisible by the GCD of M and N
    // If not, it's impossible to measure W liters
    if (W % gcd(M, N) != 0) {
        return -1;
    }
    
    // If W is greater than both M and N, we can't measure it
    if (W > max(M, N)) {
        return -1;
    }
    
    // If W equals either M or N, we can directly fill that vessel
    if (W == M || W == N) {
        return 1;
    }
    
    // BFS to find minimum steps
    queue<pair<pair<int, int>, int>> q; // ((amount in vessel 1, amount in vessel 2), steps)
    unordered_set<pair<int, int>, PairHash> visited;
    
    // Start with both vessels empty
    q.push({{0, 0}, 0});
    visited.insert({0, 0});
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        int x = curr.first.first;  // Amount in vessel 1
        int y = curr.first.second; // Amount in vessel 2
        int steps = curr.second;   // Steps taken so far
        
        // Check if we've reached the target
        if (x == W || y == W) {
            return steps;
        }
        
        // Try all possible operations:
        
        // 1. Fill vessel 1
        if (x < M && visited.find({M, y}) == visited.end()) {
            q.push({{M, y}, steps + 1});
            visited.insert({M, y});
        }
        
        // 2. Fill vessel 2
        if (y < N && visited.find({x, N}) == visited.end()) {
            q.push({{x, N}, steps + 1});
            visited.insert({x, N});
        }
        
        // 3. Empty vessel 1
        if (x > 0 && visited.find({0, y}) == visited.end()) {
            q.push({{0, y}, steps + 1});
            visited.insert({0, y});
        }
        
        // 4. Empty vessel 2
        if (y > 0 && visited.find({x, 0}) == visited.end()) {
            q.push({{x, 0}, steps + 1});
            visited.insert({x, 0});
        }
        
        // 5. Pour from vessel 1 to vessel 2
        if (x > 0 && y < N) {
            int pour = min(x, N - y);
            if (visited.find({x - pour, y + pour}) == visited.end()) {
                q.push({{x - pour, y + pour}, steps + 1});
                visited.insert({x - pour, y + pour});
            }
        }
        
        // 6. Pour from vessel 2 to vessel 1
        if (y > 0 && x < M) {
            int pour = min(y, M - x);
            if (visited.find({x + pour, y - pour}) == visited.end()) {
                q.push({{x + pour, y - pour}, steps + 1});
                visited.insert({x + pour, y - pour});
            }
        }
    }
    
    // If we've exhausted all possible states without finding a solution
    return -1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int M, N, W;
        cin >> M >> N >> W;
        
        cout << minSteps(M, N, W) << endl;
    }
    
    return 0;
}