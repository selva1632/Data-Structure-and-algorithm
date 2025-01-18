// problem link: https://leetcode.com/problems/majority-element-ii/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, n1 = -1, n2 = -1, n = nums.size();

        for (int it: nums) {
        	if (cnt1 == 0 && it != n2) {
        		cnt1++;
        		n1 = it;
        	} else if (cnt2 == 0 && it != n1) {
        		cnt2++;
        		n2 = it; 
        	} else if (it == n1) cnt1++;
        	else if (it == n2) cnt2++;
        	else {
        		cnt1--;
        		cnt2--;
        	}
        }

        vector<int> res;
        cnt1 = 0, cnt2 = 0;

        for (auto it: nums) {
        	if (it == n1) cnt1++;
        	else if (it == n2) cnt2++;
        }

        if (cnt1 > n/3) res.push_back(n1);
        if (cnt2 > n/3) res.push_back(n2);

        return res;
    }	
};