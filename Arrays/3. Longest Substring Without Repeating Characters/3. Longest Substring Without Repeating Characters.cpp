// problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int left = 0, right = 0, ans = 0, n = s.size();

        while (right < n) {
            if (mpp[s[right]] != -1)
                if (mpp[s[right]] >= left) {
                    left = mpp[s[right]] + 1;
                }
            ans = max(ans, right - left + 1);
            mpp[s[right]] = right;
            right++;
        }   
        return ans;
    }
};