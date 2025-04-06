#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int minimumCardPickup(vector<int>& cards) {
            unordered_map<int, int> mpp;
            int minDist = cards.size() + 2;
            
            for (int i = 0; i < cards.size(); i++) {
                if (mpp.find(cards[i]) != mpp.end()) {
                    int index = mpp[cards[i]];
                    minDist = min(minDist, i - index + 1);
                }
                mpp[cards[i]] = i;
            }
    
            return minDist == cards.size() + 2 ? -1 : minDist;
        }
    };

/*
    time complexity - O(N)
    space complexity - O(N)
*/