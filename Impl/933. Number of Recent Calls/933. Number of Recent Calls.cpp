// problem link: https://leetcode.com/problems/number-of-recent-calls

#include<iostream>
#include<queue>
using namespace std;

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);

        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

/*
    time complexity - O(1)
*/