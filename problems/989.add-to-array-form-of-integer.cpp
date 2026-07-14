// @leetcode id=989 questionId=1031 slug=add-to-array-form-of-integer lang=cpp site=leetcode.com title="Add to Array-Form of Integer"
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int i = num.size() - 1;
        long long carry = k;
        while (i >= 0 || carry > 0) {
            long long sum = carry;
            if (i >= 0) sum += num[i--];
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
