// @leetcode id=1437 questionId=1548 slug=check-if-all-1s-are-at-least-length-k-places-away lang=cpp site=leetcode.com title="Check If All 1's Are at Least Length K Places Away"
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 1) {
                if (last != -1 && i - last <= k) return false;
                last = i;
            }
        }
        return true;
    }
};
