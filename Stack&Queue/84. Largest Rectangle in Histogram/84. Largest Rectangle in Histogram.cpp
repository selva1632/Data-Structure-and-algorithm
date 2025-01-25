// problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    vector<int> findNSE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> findNPE(vector<int> &arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findNPE(heights);
        int n = heights.size(), maxi = 0;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] -1));
        }
        return maxi;
    }
};