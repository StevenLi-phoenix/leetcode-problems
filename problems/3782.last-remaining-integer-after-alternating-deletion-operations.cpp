// @leetcode id=3782 questionId=4164 slug=last-remaining-integer-after-alternating-deletion-operations lang=cpp site=leetcode.com title="Last Remaining Integer After Alternating Deletion Operations"
class Solution {
public:
    long long lastInteger(long long n) {
        long long first = 1, step = 1, count = n;
        bool fromLeft = true;

        while (count > 1) {
            if (fromLeft) {
                // keep 1st, 3rd, ... from the left
            } else {
                // keep 1st, 3rd, ... from the right; smallest kept
                // 0-based index is (count-1) % 2
                first += ((count - 1) % 2) * step;
            }
            step *= 2;
            count = (count + 1) / 2;
            fromLeft = !fromLeft;
        }
        return first;
    }
};
