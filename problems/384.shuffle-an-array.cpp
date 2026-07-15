// @leetcode id=384 questionId=384 slug=shuffle-an-array lang=cpp site=leetcode.com title="Shuffle an Array"
class Solution {
public:
    vector<int> original;
    vector<int> current;

    Solution(vector<int>& nums) {
        original = nums;
        current = nums;
    }

    vector<int> reset() {
        current = original;
        return current;
    }

    vector<int> shuffle() {
        int n = current.size();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(current[i], current[j]);
        }
        return current;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
