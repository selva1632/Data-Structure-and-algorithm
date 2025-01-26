// problem link: https://leetcode.com/problems/merge-k-sorted-lists/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
    #define pair pair<int, ListNode*>
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair, vector<pair>, greater<pair>> pq;

        for (auto list: lists) {
            while (list) {
                pq.push({list->val, list});
                list = list->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (!pq.empty()) {
            cur->next = pq.top().second;
            cur = cur->next;
            pq.pop();
        }

        return dummy->next;
    }
};