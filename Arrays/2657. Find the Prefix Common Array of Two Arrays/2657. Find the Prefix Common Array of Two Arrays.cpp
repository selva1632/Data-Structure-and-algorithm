// problem link https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n, 0);
        unordered_map<int, int> mpp;
        int common = 0;
        for (int i = 0; i < n; i++) {
            mpp[A[i]]++;
            if (mpp[A[i]] == 2) {
                common++;
            }
            mpp[B[i]]++;
            if (mpp[B[i]] == 2) {
                common++;
            }

            res[i] = common;
        }
        return res;
    }
};