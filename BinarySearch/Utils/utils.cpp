#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

int upperBound(vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1, ans = -1;

    while (l <= r) {
        int mid = l + (r-l) / 2;

        if (arr[mid] > x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    } 
    return ans;
}

int lowerBound(vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1, ans = -1;

    while (l <= r) {
        int mid = l + (r-l) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else {
          l = mid + 1;
        }
    } 
    return ans;
}
