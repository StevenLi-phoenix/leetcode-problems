// @leetcode id=2386 questionId=2462 slug=find-the-k-sum-of-an-array lang=cpp site=leetcode.com title="Find the K-Sum of an Array"
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long total = 0;
        vector<long long> absVals;
        for (int x : nums) {
            if (x > 0) total += x;
            absVals.push_back(abs((long long)x));
        }
        sort(absVals.begin(), absVals.end());
        int n = absVals.size();

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> heap;
        if (n > 0) heap.push({absVals[0], 0});

        long long result = total;
        int count = 1;

        while (count < k) {
            auto [curSum, idx] = heap.top();
            heap.pop();
            count++;
            if (count == k) {
                result = total - curSum;
                break;
            }
            if (idx + 1 < n) {
                heap.push({curSum + absVals[idx + 1] - absVals[idx], idx + 1});
                heap.push({curSum + absVals[idx + 1], idx + 1});
            }
        }

        return result;
    }
};
