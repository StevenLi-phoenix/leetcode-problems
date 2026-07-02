// @leetcode id=2037 questionId=2148 slug=minimum-number-of-moves-to-seat-everyone lang=cpp site=leetcode.com title="Minimum Number of Moves to Seat Everyone"
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;
        for (int i = 0; i < (int)seats.size(); i++) {
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};
