// problem link: https://leetcode.com/problems/course-schedule-iv/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> mat(numCourses, vector<int>(numCourses, 1e9));

        for (auto p: prerequisites) {
            mat[p[0]][p[1]] = 1;
            mat[p[1]][p[0]] = 1;
        }

        for (int via = 0; via < numCourses; via++) {
            for (int i = 0; i  < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }   
        }

        vector<bool> res;
        for (auto q: queries) {
            if (mat[q[0]][q[1]] >= 1e9) {
                res.push_back(false);
            } else {
                res.push_back(true);
            }
        }
        return res;
    }
};