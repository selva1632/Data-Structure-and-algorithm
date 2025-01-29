// problem link: https://leetcode.com/problems/seat-reservation-manager/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class SeatManager {
    int marker;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        marker = 1;
    }
    
    int reserve() {
        if (!pq.empty()) {
            int seatNo = pq.top();
            pq.pop();

            return seatNo;
        }

        int seatNo = marker;
        ++marker;
        return seatNo;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


/*
    time complexity - O(m⋅logn)
    space complexity - O(n)
*/