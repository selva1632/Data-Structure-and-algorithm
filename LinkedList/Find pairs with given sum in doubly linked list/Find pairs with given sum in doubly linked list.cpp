// problem link: https://bit.ly/3zWPiBj

#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> res;
        unordered_map<int, int> mpp;
        
        while (head) {
            int val = head->data;
            if (mpp.find(target - val) != mpp.end()) {
                res.push_back({target - val, val});
            }
            mpp[val] = val;
            head = head->next;
        }
        sort(res.begin(), res.end());
        return res;
    }
};