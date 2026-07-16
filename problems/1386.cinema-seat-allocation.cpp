// @leetcode id=1386 questionId=1487 slug=cinema-seat-allocation lang=cpp site=leetcode.com title="Cinema Seat Allocation"
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for (auto& r : reservedSeats) {
            int row = r[0], seat = r[1];
            rowMask[row] |= (1 << (seat - 1));
        }

        const int mask1 = 0b0011110;  // seats 2-5
        const int mask2 = 0b1111000;  // seats 4-7
        const int mask3 = 0b111100000; // seats 6-9

        long long total = (long long)(n - (int)rowMask.size()) * 2;

        for (auto& [row, mask] : rowMask) {
            int m = mask;
            if ((m & mask1) == 0) { total++; m |= mask1; }
            if ((m & mask3) == 0) { total++; m |= mask3; }
            else if ((m & mask2) == 0) { total++; }
        }
        return (int)total;
    }
};
