// @leetcode id=1785 questionId=1911 slug=minimum-elements-to-add-to-form-a-given-sum lang=cpp site=leetcode.com title="Minimum Elements to Add to Form a Given Sum"
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int x : nums) sum += x;
        long long diff = abs((long long)goal - sum);
        return (int)((diff + limit - 1) / limit);
    }
};
