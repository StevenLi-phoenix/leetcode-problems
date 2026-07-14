// @leetcode id=229 questionId=229 slug=majority-element-ii lang=cpp site=leetcode.com title="Majority Element II"
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 0, count1 = 0, count2 = 0;
        bool has1 = false, has2 = false;

        for (int n : nums) {
            if (has1 && n == cand1) {
                count1++;
            } else if (has2 && n == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = n;
                count1 = 1;
                has1 = true;
            } else if (count2 == 0) {
                cand2 = n;
                count2 = 1;
                has2 = true;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int n : nums) {
            if (has1 && n == cand1) count1++;
            else if (has2 && n == cand2) count2++;
        }

        vector<int> result;
        int threshold = nums.size() / 3;
        if (has1 && count1 > threshold) result.push_back(cand1);
        if (has2 && count2 > threshold) result.push_back(cand2);
        return result;
    }
};
