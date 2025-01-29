// problem link: https://leetcode.com/problems/lemonade-change/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twentys = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                fives++;
            } else if (bills[i] == 10) {
                if (fives <= 0) {
                    return false;
                }
                fives--;
                tens++;
            } else {
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }   
        return true;
    }
};