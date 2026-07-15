// @leetcode id=3676 questionId=4000 slug=count-bowl-subarrays lang=cpp site=leetcode.com title="Count Bowl Subarrays"
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextGreaterRight(n, -1), nextGreaterLeft(n, -1);

        vector<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && nums[stack.back()] < nums[i]) {
                nextGreaterRight[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        stack.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && nums[stack.back()] < nums[i]) {
                nextGreaterLeft[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        long long count = 0;
        for (int i = 0; i < n; i++) {
            if (nextGreaterRight[i] != -1 && nextGreaterRight[i] - i >= 2) count++;
            if (nextGreaterLeft[i] != -1 && i - nextGreaterLeft[i] >= 2) count++;
        }
        return count;
    }
};
