// @leetcode id=551 questionId=551 slug=student-attendance-record-i lang=cpp site=leetcode.com title="Student Attendance Record I"
class Solution {
public:
    bool checkRecord(string s) {
        int absences = 0, consecutiveLate = 0;
        for (char c : s) {
            if (c == 'A') absences++;
            if (c == 'L') consecutiveLate++;
            else consecutiveLate = 0;

            if (absences >= 2 || consecutiveLate >= 3) return false;
        }
        return true;
    }
};
