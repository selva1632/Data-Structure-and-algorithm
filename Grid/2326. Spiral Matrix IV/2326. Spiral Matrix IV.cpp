// problem link: https://leetcode.com/problems/spiral-matrix-iv/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        while (left <= right && top <= bottom && head) {
            for (int i = left; i <= right && head; i++) {
                res[top][i] = head->val;
                head = head->next;
            }
            top++;

            for (int i = top; i <= bottom && head; i++) {
                res[i][right] = head->val;
                head = head->next;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left && head; i--) {
                    res[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top && head; i--) {
                    res[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
        }
        return res;
    }
};