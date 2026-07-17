// @leetcode id=2454 questionId=2549 slug=next-greater-element-iv lang=cpp site=leetcode.com title="Next Greater Element IV"
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, -1);
        vector<int> s1, s2; // stacks of indices, decreasing values top to bottom

        for (int i = 0; i < n; i++) {
            while (!s2.empty() && nums[s2.back()] < nums[i]) {
                answer[s2.back()] = nums[i];
                s2.pop_back();
            }

            vector<int> temp;
            while (!s1.empty() && nums[s1.back()] < nums[i]) {
                temp.push_back(s1.back());
                s1.pop_back();
            }
            for (int j = temp.size() - 1; j >= 0; j--) s2.push_back(temp[j]);

            s1.push_back(i);
        }

        return answer;
    }
};
