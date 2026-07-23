// @leetcode id=3917 questionId=4295 slug=count-indices-with-opposite-parity lang=cpp site=leetcode.com title="Count Indices With Opposite Parity"
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        int oddCount = 0, evenCount = 0;

        for (int i = n - 1; i >= 0; i--) {
            answer[i] = (nums[i] % 2 == 0) ? oddCount : evenCount;
            if (nums[i] % 2 == 0) evenCount++;
            else oddCount++;
        }
        return answer;
    }
};
