// problem link: https://leetcode.com/problems/majority-element/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt = 0, num = 0;

		for (int i =0 ; i <n; i++) {
			if (cnt == 0) {
				num = nums[i];
				cnt++;
			} else if (num == nums[i]) { cnt++; } 
			else { cnt--;}
		}

		cnt = 0;
		for (int i = 0; i < n; i++) { 
			if (num == nums[i]) cnt++; 
		}
		if (cnt > n/2) return num;
		return -1; 
		
    }
};