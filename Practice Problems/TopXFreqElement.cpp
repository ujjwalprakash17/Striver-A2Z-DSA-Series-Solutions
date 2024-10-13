#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (const auto& entry : freqMap) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> topK;
    while (!minHeap.empty()) {
        topK.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    // Reverse the vector to have the most frequent elements at the beginning
    reverse(topK.begin(), topK.end());
    return topK;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
    int k = 2; // Change as needed
    vector<int> result = topKFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
