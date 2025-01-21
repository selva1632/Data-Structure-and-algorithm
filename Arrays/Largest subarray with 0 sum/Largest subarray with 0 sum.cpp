// problem link: https://bit.ly/3w5QSzC

#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        unordered_map<long long, int> mpp;
        long long sum = 0;
        int maxLen = 0, n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) maxLen = max(maxLen, i + 1);

            long long rem = sum;
            if (mpp.find(rem) != mpp.end()) {
                maxLen = max(maxLen, i - mpp[rem]);
            }
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }

        return maxLen;
    }
};