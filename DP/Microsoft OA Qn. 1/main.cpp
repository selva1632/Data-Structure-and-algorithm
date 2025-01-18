#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Question
/*
    A group of explorers is heading for an expedition into a cave. We know that the cave can be represented as a rectangular map consisting of N rows and M columns.
    Rows represent levels of the cave and are numbered from 0 to N-1 from top to bottom. 
    Columns are numbered from 0 to M-1 from left to right and represent consecutive chambers on each level of the cave.
    Explorers can get through some chambers (marked'.') without any problem, 
    but some other chambers (marked 'x') are impossible to pass through as they contain too much debris and are unsafe.
    The expedition starts at the top-left corner (0, 0) of the cave and its goal is to get to the exit in the bottom-right corner (N-1, M-1). 
    Explorers can move only to the chamber on the left, the chamber on the right or climb down to the lower level. 
    Climbing up is too dangerous, so there is no possibility to move to the upper level after moving to a lower one. Formally,
    if the expedition is in chamber (R, C), the next chamber on their path may be only one of the following:
    (R+1, C), (R, C-1), (R, C+1).

    The explorers want to plan their path through the cave to explore as many chambers as possible. As the chambers may be very narrow,
    they do not want to be forced to move back during the expedition. In other words, the explorers do not want to enter a chamber they have already been in before.
    Chambers outside the map are considered unsafe. The expedition can never enter any unsafe chamber.
    What is the maximum number of chambers the explorers can visit during the expedition? 
    If it would be impossible to reach chamber (N-1, M-1), for reasons of safety, the expedition should be canceled.
    Write a function:
    int solution (vector &B);
    that, given an array B consisting of N strings of equal length M, representing the map of the cave, 
    returns the maximum number of chambers the expedition can explore on its way from chamber (0, 0) to the exit in chamber (N-1, M-1).
    If there is no possibility for the expedition to get to the chamber with the exit, the function should return -1.
*/

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m) {
    // edge cases
    if (i < 0 || j < 0 || j >= m) {
        return -1e9;
    }

    if (grid[i][j] == 1) {
        return -1e9;
    }

    // destination
    if (i == 0 && j == 0) {
        return grid[0][0] == 0 ? 1 : -1e9;
    }

    // memo
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // marking node as visited
    grid[i][j] = 1;

    int left = f(i, j - 1, grid, dp, n, m);
    int right = f(i, j + 1, grid, dp, n, m);
    int up = f(i - 1, j, grid, dp, n, m);

    return dp[i][j] = 1 + max(left, max(right, up));
}

int main() {
    int times, n, m;
    cin >> times;

    while (times-- > 0) {
        cin >> n >> m;

        // grid
        vector<vector<int>> grid(n, vector<int>(m));
        // dp
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        // start at (n - 1, m - 1)
        // trying to reach (0, 0)
        int ans = f(n - 1, m - 1, grid, dp, n, m);
        if (ans < 0) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}