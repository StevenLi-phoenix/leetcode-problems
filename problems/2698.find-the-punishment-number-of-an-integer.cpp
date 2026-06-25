// @leetcode id=2698 questionId=2802 slug=find-the-punishment-number-of-an-integer lang=cpp site=leetcode.com title="Find the Punishment Number of an Integer"
class Solution {
public:
    bool canPartition(string s, int target, int pos) {
        if (pos == s.size()) return target == 0;
        if (target < 0) return false;
        
        int num = 0;
        for (int i = pos; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
            if (canPartition(s, target - num, i + 1)) return true;
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            string sq = to_string(i * i);
            if (canPartition(sq, i, 0)) {
                result += i * i;
            }
        }
        return result;
    }
};
