// @leetcode id=1462 questionId=1558 slug=course-schedule-iv lang=cpp site=leetcode.com title="Course Schedule IV"
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reach(numCourses, vector<bool>(numCourses, false));
        for (auto& p : prerequisites) reach[p[0]][p[1]] = true;

        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                if (!reach[i][k]) continue;
                for (int j = 0; j < numCourses; j++) {
                    if (reach[k][j]) reach[i][j] = true;
                }
            }
        }

        vector<bool> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            result.push_back(reach[q[0]][q[1]]);
        }
        return result;
    }
};
