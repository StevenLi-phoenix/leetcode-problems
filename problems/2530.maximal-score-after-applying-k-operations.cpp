// @leetcode id=2530 questionId=2616 slug=maximal-score-after-applying-k-operations lang=cpp site=leetcode.com title="Maximal Score After Applying K Operations"
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> maxHeap(nums.begin(), nums.end());
        long long score = 0;
        for (int i = 0; i < k; i++) {
            long long top = maxHeap.top();
            maxHeap.pop();
            score += top;
            maxHeap.push((top + 2) / 3);
        }
        return score;
    }
};
