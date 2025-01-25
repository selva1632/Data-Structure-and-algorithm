// problem link: https://leetcode.com/problems/maximal-rectangle/
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

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findNPE(heights);
        int n = heights.size(), maxi = 0;
        
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] -1));
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        int sum;

        for (int j = 0; j < m; j++) {
            sum = 0;
            for (int i = 0; i < n; i++) {
                sum += matrix[i][j] - '0';

                if (matrix[i][j] == '0') {
                    sum = 0;
                }

                prefixSum[i][j] = sum;
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, largestRectangleArea(prefixSum[i]));
        }
        return maxi;
    }
};