// @leetcode id=667 questionId=667 slug=beautiful-arrangement-ii lang=cpp site=leetcode.com title="Beautiful Arrangement II"
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int left = 1, right = k + 1;

        for (int i = 0; i <= k; i++) {
            if (i % 2 == 0) {
                result.push_back(left);
                left++;
            } else {
                result.push_back(right);
                right--;
            }
        }

        for (int i = k + 2; i <= n; i++) {
            result.push_back(i);
        }

        return result;
    }
};
