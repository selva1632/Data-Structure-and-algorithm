// problem link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0, platform = 0, ans = 0, n = arr.size();
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platform++;
                i++; 
            } else {
                platform--;
                j++;
            }
            ans = max(ans, platform);
        }
        return ans;
    }
};