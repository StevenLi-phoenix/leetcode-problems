// @leetcode id=2488 questionId=2574 slug=count-subarrays-with-median-k lang=cpp site=leetcode.com title="Count Subarrays With Median K"
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int pos = -1;
        for (int i = 0; i < n; i++) if (nums[i] == k) { pos = i; break; }

        vector<int> score(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > k) score[i] = 1;
            else if (nums[i] < k) score[i] = -1;
            else score[i] = 0;
        }

        unordered_map<int, int> leftMap;
        int leftSum = 0;
        leftMap[0] = 1;
        for (int l = pos - 1; l >= 0; l--) {
            leftSum += score[l];
            leftMap[leftSum]++;
        }

        long long ans = 0;
        int rightSum = 0;
        for (int r = pos; r < n; r++) {
            rightSum += score[r];
            auto it1 = leftMap.find(-rightSum);
            if (it1 != leftMap.end()) ans += it1->second;
            auto it2 = leftMap.find(1 - rightSum);
            if (it2 != leftMap.end()) ans += it2->second;
        }

        return (int)ans;
    }
};
