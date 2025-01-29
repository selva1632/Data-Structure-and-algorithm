// problem link: https://leetcode.com/problems/range-sum-query-immutable/

#include<iostream>
#include<vector>
using namespace std;

class SegmentTree {
    #define MAX 10005
    int seg[4 * MAX];

public:
    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int rangeSum(int ind, int low, int high, int l, int r) {
        if (high < l || r < low) 
            return 0;

        if (l <= low && high <= r) {
            return seg[ind];
        }

        int mid = low + (high - low) / 2;
        int left = rangeSum(2 * ind + 1, low, mid, l, r);
        int right = rangeSum(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

class NumArray {
    SegmentTree st;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st = SegmentTree();
        st.build(0, 0, n - 1, nums);
    }
    
    int sumRange(int left, int right) {
        return st.rangeSum(0, 0, n - 1, left, right);
    }
};

/*

    time complexity - O(N)
    space complexity - O(4 * N)

*/