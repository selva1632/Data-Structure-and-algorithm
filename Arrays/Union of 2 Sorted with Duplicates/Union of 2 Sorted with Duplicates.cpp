// problem link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
        vector<int> findUnion(vector<int> &a, vector<int> &b) {
                int n = a.size(), m = b.size();
        int i = 0, j = 0;
        vector<int> res;
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                if (res.empty() || res.back() != a[i]) {
                    res.push_back(a[i]);
                }
                i++;
            } else if (a[i] > b[j]) {
                if (res.empty() || res.back() != b[j]) {
                    res.push_back(b[j]);
                }
                j++;
            } else {
                if (res.empty() || res.back() != a[i]) {
                    res.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        while (i < n) {
            if (res.empty() || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
        }
        while (j < m) {
            if (res.empty() || res.back() != b[j]) {
                res.push_back(b[j]);
            }
            j++;
        }

        return res;
    }

};

/*
    time complexity - O(N + M)
    space complexity - O(N + M)
*/