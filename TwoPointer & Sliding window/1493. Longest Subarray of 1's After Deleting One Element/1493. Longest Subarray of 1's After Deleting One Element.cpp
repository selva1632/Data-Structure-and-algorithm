#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int l = 0, r = 0, n = nums.size();
            int zero = 0;
            int ans = 0;
    
            while (r < n) {
                if (nums[r] == 0) {
                    zero++;
                }
    
                if (zero > 1) {
                    ans = max(ans, r - l - 1);
                    while (l < r && nums[l] != 0) {
                        l++;
                    }
                    zero--;
                    l++;
                }
                r++;
            }
    
            ans = max(ans, r - l - 1);
    
            return ans;
        }
    };

/*
    time complexity - O(N)
    space complexity - O(1)
*/