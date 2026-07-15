// @leetcode id=3309 questionId=3579 slug=maximum-possible-number-by-binary-concatenation lang=cpp site=leetcode.com title="Maximum Possible Number by Binary Concatenation"
class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int best = 0;
        do {
            string bits;
            for (int n : nums) bits += bitset<32>(n).to_string().substr(32 - bitLen(n));
            best = max(best, stoi(bits, nullptr, 2));
        } while (next_permutation(nums.begin(), nums.end()));
        return best;
    }

private:
    int bitLen(int n) {
        int len = 0;
        while (n > 0) { len++; n >>= 1; }
        return len;
    }
};
