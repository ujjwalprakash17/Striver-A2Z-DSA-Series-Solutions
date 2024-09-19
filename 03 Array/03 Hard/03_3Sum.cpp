#include <bits/stdc++.h>
using namespace std;

// Brute force solution
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>>setStore;
//     for(int i = 0; i < nums.size() ; i++)
//     {
//         for(int j = i + 1; j < nums.size() ; j++)
//         {
//             for(int k = j + 1; k < nums.size(); k++)
//             {
//                 if(nums[i] + nums[j] + nums[k] == 0)
//                 {
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());
//                     setStore.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(setStore.begin(), setStore.end());
//     return ans;
// }


//Better Approach -> 
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>>setStore;
//     unordered_map<int, int> mp;
//     for(int i = 0; i < nums.size(); i++)
//     {
//         mp[nums[i]]++;
//     }
//     for(int i = 0; i < nums.size() ; i++)
//     {
//         for(int j = 0; j < nums.size() ; j++)
//         {
//             if(i == j) continue;
//             int val = - (nums[i] + nums[j]);
//             if(mp.find(val) != mp.end()){
//                 vector<int> temp = {nums[i] , nums[j], val};
//                 sort(temp.begin(), temp.end());
//                 setStore.insert(temp);
//             }
//         }
//     }
//     vector<vector<int>> ans(setStore.begin(), setStore.end());
//     return ans;
// }
// vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
// 	// Write your code here.
// 	unordered_map<int, int> mp;
// 	for(int i = 0; i < n; i++){
// 		mp[arr[i]]++;
// 	}
// 	set<vector<int>> setStore;
// 	for(int i = 0; i < n ; i++){
// 		for(int j = 0; j < n ;j++){
// 			int val = -(arr[i] + arr[j]);
// 			if(mp.find(val) != mp.end()){
// 				vector<int> temp = {arr[i], arr[j], val};
// 				sort(temp.begin(), temp.end());
// 				setStore.insert(temp);
// 			}
// 		}
// 	}
// 	vector<vector<int>>ans(setStore.begin(), setStore.end());
// 	return ans;
// }
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> setStore;
    for(int i = 0; i < n ; i++){
        set<int> hashSet;
        for(int j = i + 1 ; j < n ; j++){
            int val = -(arr[i] + arr[j]);
            if(hashSet.find(val) != hashSet.end()){
                vector<int> temp = {arr[i], arr[j] , val};
                sort(temp.begin(), temp.end());
                setStore.insert(temp);
            }
            hashSet.insert(val);
        }
    }
    vector<vector<int>> ans (setStore.begin(), setStore.end());
    return ans;
}
//most optimal approach 
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n ;i++){
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        int j = i +1;
        int k = n -1;
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++, k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> sample = {-1,0,1,2,-1,-4};
    int n = sample.size();
    triplet(n ,sample);
    return 0;
}