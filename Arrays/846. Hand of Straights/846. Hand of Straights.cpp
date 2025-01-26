// problem link: 

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> mpp;
        for (auto it: hand) {
            mpp[it]++;
        }

        while (!mpp.empty()) {
            int currentCard = mpp.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                if (mpp[currentCard + i] == 0) {
                    return false;
                }
                mpp[currentCard + i]--;
                if (mpp[currentCard + i] < 1) {
                    mpp.erase(currentCard + i);
                }
            }
        }
        return true;
    }
};