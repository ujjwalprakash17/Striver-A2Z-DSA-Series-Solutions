#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

class NextGreaterCounter {
public:
    // Brute Force Approach - O(n²) time, O(1) extra space
    static vector<int> countNextGreaterBruteForce(const vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);
        
        // For each element, count greater elements to its right
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    count++;
                }
            }
            result[i] = count;
        }
        
        return result;
    }
    
    // Optimized Stack Approach - O(n) time, O(n) extra space
    static vector<int> countNextGreaterOptimized(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        
        vector<int> result(n, 0);
        stack<int> stk; // Stack to store indices
        
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements from stack that are <= current element
            while (!stk.empty() && arr[stk.top()] <= arr[i]) {
                stk.pop();
            }
            
            // Count of elements in stack = count of greater elements
            result[i] = stk.size();
            
            // Push current index to stack
            stk.push(i);
        }
        
        return result;
    }
    
    // Alternative: Using monotonic stack (process left to right)
    static vector<int> countNextGreaterMonotonic(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        
        vector<int> result(n, 0);
        stack<int> stk; // Stack stores indices of elements waiting for their next greater
        
        for (int i = 0; i < n; i++) {
            // Current element is the next greater for elements in stack
            while (!stk.empty() && arr[stk.top()] < arr[i]) {
                int idx = stk.top();
                stk.pop();
                // For the popped element, we need to count all elements greater than it
                // This approach needs modification - let's use the simpler right-to-left
            }
            stk.push(i);
        }
        
        // This approach is more complex for counting, stick with right-to-left
        return countNextGreaterOptimized(arr);
    }
};

// Utility functions for testing and demonstration
class TestUtils {
public:
    static void printVector(const vector<int>& vec, const string& label = "") {
        if (!label.empty()) cout << label << ": ";
        cout << "[";
        for (size_t i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    static void traceExample(const vector<int>& arr) {
        cout << "Tracing step by step:" << endl;
        cout << "Array: ";
        printVector(arr);
        cout << string(50, '=') << endl;
        
        for (size_t i = 0; i < arr.size(); i++) {
            cout << "Position " << i << " (value = " << arr[i] << "):" << endl;
            cout << "  Looking right at: [";
            
            int count = 0;
            vector<int> greaterElements;
            
            for (size_t j = i + 1; j < arr.size(); j++) {
                cout << arr[j];
                if (j < arr.size() - 1) cout << ", ";
                
                if (arr[j] > arr[i]) {
                    count++;
                    greaterElements.push_back(arr[j]);
                }
            }
            cout << "]" << endl;
            
            cout << "  Greater elements: ";
            printVector(greaterElements);
            cout << "  Count: " << count << endl << endl;
        }
    }
    
    static void runTests() {
        vector<vector<int>> testCases = {
            {3, 1, 4, 2, 5},    // Main example
            {5, 4, 3, 2, 1},    // Descending order
            {1, 2, 3, 4, 5},    // Ascending order
            {2, 2, 2, 2},       // All equal
            {7},                // Single element
            {},                 // Empty array
            {1, 3, 2, 4}        // Mixed case
        };
        
        cout << "Running Tests:" << endl;
        cout << string(60, '=') << endl;
        
        for (size_t i = 0; i < testCases.size(); i++) {
            const auto& arr = testCases[i];
            auto bruteResult = NextGreaterCounter::countNextGreaterBruteForce(arr);
            auto optimizedResult = NextGreaterCounter::countNextGreaterOptimized(arr);
            
            cout << "Test " << (i + 1) << ":" << endl;
            printVector(arr, "Input   ");
            printVector(bruteResult, "Brute   ");
            printVector(optimizedResult, "Optimized");
            
            // Verify both methods give same result
            assert(bruteResult == optimizedResult);
            cout << "✓ Both methods match!" << endl;
            cout << string(30, '-') << endl;
        }
    }
};

// Performance comparison
class PerformanceTest {
public:
    static void comparePerformance() {
        cout << "Performance Analysis:" << endl;
        cout << "Brute Force: O(n²) time, O(1) extra space" << endl;
        cout << "Stack-based: O(n) time, O(n) extra space" << endl;
        cout << "For large arrays, stack-based is significantly faster!" << endl;
    }
};

int main() {
    // Main example walkthrough
    vector<int> example = {3, 1, 4, 2, 5};
    cout << "PROBLEM: Number of Next Greater Elements to the Right" << endl;
    cout << string(60, '=') << endl << endl;
    
    TestUtils::traceExample(example);
    
    // Show both solutions
    cout << "Solutions:" << endl;
    auto bruteResult = NextGreaterCounter::countNextGreaterBruteForce(example);
    auto stackResult = NextGreaterCounter::countNextGreaterOptimized(example);
    
    TestUtils::printVector(example, "Input        ");
    TestUtils::printVector(bruteResult, "Brute Force  ");
    TestUtils::printVector(stackResult, "Stack-based  ");
    cout << endl;
    
    // Run comprehensive tests
    TestUtils::runTests();
    
    // Performance note
    PerformanceTest::comparePerformance();
    
    return 0;
}