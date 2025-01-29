// problem link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    // Nlog(n)
    int countNum(vector<vector<int>>& mat, int x) {
        int cnt = 0, n = mat.size();

        for (int i = 0; i < n; i++) {
            auto ub = upper_bound(mat[i].begin(), mat[i].end(), x);
            cnt += (ub - mat[i].begin());
        }

        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l =  matrix[0][0], r = matrix[matrix.size() - 1][matrix[0].size() - 1];
        int ans = -1;

        while (l <= r) { // O(log(R))
            int mid = l + (r - l) / 2;

            int occurence = countNum(matrix, mid);
            if (occurence >= k) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};

/*

    time complexity - O(log(R) * Nlog(N))  R - range (min, max) N - column size
    space - O(1)

*/