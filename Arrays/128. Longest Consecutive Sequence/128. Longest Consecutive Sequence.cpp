// problem link: https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int longest = 0;

        for (auto it: nums) {
            st.insert(it);
        }

        for (auto it: st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    cnt++;
                    x++;
                }
                longest = max(cnt, longest);
            }
        }

        return longest;
    }
};