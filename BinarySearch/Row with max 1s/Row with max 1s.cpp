// problem link: https://bit.ly/3QNDw2W

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = -1, maxOnes = -1;
        
        for (int i = 0; i < arr.size(); i++) {
            int first = findFirst(arr[i]);
            if (first == -1) continue;
            
            int last = findLast(arr[i]);
            
            int ones = last - first + 1;
            if (maxOnes < ones) {
                ans = i;
                maxOnes = ones;
            }
        }
        
        return ans;
    }
    
    int findLast(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, ans = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (arr[mid] == 1) {
                ans = mid;
                l = mid + 1;
            } else if (arr[mid] < 1) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return ans;
    }
    
    int findFirst(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, ans = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (arr[mid] == 1) {
                ans = mid;
                r = mid - 1;
                
            } else if (arr[mid] < 1) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};