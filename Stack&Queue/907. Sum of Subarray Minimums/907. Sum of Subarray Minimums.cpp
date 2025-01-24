// problem link: https://leetcode.com/problems/sum-of-subarray-minimums/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top() ;
            st.push(i);
        }
        return res;
    }

    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSE = findNSE(arr);
        vector<int> PSE = findPSE(arr);
        long long total = 0, MOD = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            int left = i - PSE[i];
            int right = NSE[i] - i;

            total = (total + (((left * right) % MOD) * arr[i]) % MOD) % MOD;
        }
        return total;
    }
};