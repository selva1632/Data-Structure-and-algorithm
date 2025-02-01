// problem link:

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp;
        unordered_set<string> wordTaken;
        vector<string> temp;
        int i = 0, n = s.size();

        // split the s by space & store it in temporary list
        while (i < n) {
            if (i < n && s[i] == ' ') i++;
            int j = i;
            while (j < n && s[j] != ' ') j++;
            string substring = s.substr(i, j - i);
            temp.push_back(substring);
            i = j;
        }

        // both size is not match
        if (pattern.size() != temp.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            char key = pattern[i];
            string value = temp[i];

            if (mpp.find(key) != mpp.end()) {
                if (mpp[key] != value) {
                    return false;
                }
            } else {
                if (wordTaken.find(value) == wordTaken.end()) {
                    mpp[key] = value;
                    wordTaken.insert(value);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
    time complexity - O(N)
    space complexity - O(N)
*/