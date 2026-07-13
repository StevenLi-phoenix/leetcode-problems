// @leetcode id=1227 questionId=1362 slug=airplane-seat-assignment-probability lang=cpp site=leetcode.com title="Airplane Seat Assignment Probability"
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // Classic result: for n > 1, by symmetry the first passenger ends
        // up either in seat 1 or seat n with equal probability (all other
        // outcomes recursively reduce to the same sub-problem), so the
        // answer is always 0.5.
        return n == 1 ? 1.0 : 0.5;
    }
};
