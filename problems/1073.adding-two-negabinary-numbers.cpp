// @leetcode id=1073 questionId=1148 slug=adding-two-negabinary-numbers lang=cpp site=leetcode.com title="Adding Two Negabinary Numbers"
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        int carry = 0;
        vector<int> result;

        while (i >= 0 || j >= 0 || carry != 0) {
            int a = (i >= 0) ? arr1[i--] : 0;
            int b = (j >= 0) ? arr2[j--] : 0;
            int sum = a + b + carry;
            int digit = ((sum % 2) + 2) % 2;
            carry = (sum - digit) / (-2);
            result.push_back(digit);
        }

        while (result.size() > 1 && result.back() == 0) result.pop_back();
        reverse(result.begin(), result.end());
        return result;
    }
};
