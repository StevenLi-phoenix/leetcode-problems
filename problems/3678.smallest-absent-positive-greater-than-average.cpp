// @leetcode id=3678 questionId=4011 slug=smallest-absent-positive-greater-than-average lang=cpp site=leetcode.com title="Smallest Absent Positive Greater Than Average"
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double avg = 0;
        for (int x : nums) avg += x;
        avg /= nums.size();
        
        set<int> s(nums.begin(), nums.end());
        int x = max(1, (int)floor(avg) + 1);
        while (s.count(x)) x++;
        return x;
    }
};
