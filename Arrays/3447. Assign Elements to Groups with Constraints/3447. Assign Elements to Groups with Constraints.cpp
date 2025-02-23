// problem link: https://leetcode.com/problems/assign-elements-to-groups-with-constraints/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
    public:
        vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            unordered_map<int, int> elementMap;
            for (int i = 0; i < elements.size(); i++) {
                if (!elementMap.count(elements[i])) elementMap[elements[i]] = i;
            }
    
            vector<int> res;
            for (auto size: groups) {
                int minIndex = INT_MAX;
                for (auto divisor = 1; divisor * divisor <= size; divisor++) {
                    if (size % divisor == 0) {
                        if (elementMap.count(divisor)) minIndex = min(minIndex, elementMap[divisor]);
                        if (elementMap.count(size / divisor)) minIndex = min(minIndex, elementMap[size / divisor]);
                    }
                }
                res.push_back((minIndex == INT_MAX) ? -1: minIndex);
            }
            return res;
        }
    };


/*
    time complexity - O(E + G * √S) 
    E - size of the Elements array
    G - size of group array
    S - max element in groups array

    space complexity - O(1)
*/