// @leetcode id=2763 questionId=2849 slug=sum-of-imbalance-numbers-of-all-subarrays lang=cpp site=leetcode.com title="Sum of Imbalance Numbers of All Subarrays"
class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            multiset<int> s;
            int curImbalance = 0;

            for (int j = i; j < n; j++) {
                int v = nums[j];
                auto it = s.lower_bound(v);
                bool hasSucc = (it != s.end());
                bool hasPred = (it != s.begin());
                int succ = hasSucc ? *it : 0;
                int pred = hasPred ? *prev(it) : 0;

                int oldGap = (hasPred && hasSucc && succ - pred > 1) ? 1 : 0;
                int newGapLeft = (hasPred && v - pred > 1) ? 1 : 0;
                int newGapRight = (hasSucc && succ - v > 1) ? 1 : 0;

                curImbalance += newGapLeft + newGapRight - oldGap;

                s.insert(v);
                answer += curImbalance;
            }
        }

        return (int)answer;
    }
};
