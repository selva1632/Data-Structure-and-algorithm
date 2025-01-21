#include<iostream>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int first = findFirst(arr, target);
        if (first == -1) return 0;
        int last = findLast(arr, target);
        
        return last - first + 1;
    }
private:
    int findFirst(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1, ans = -1;
        
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (arr[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int findLast(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1, ans = -1;
        
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (arr[mid] <= target) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};