// @leetcode id=1588 questionId=1693 slug=sum-of-all-odd-length-subarrays lang=cpp site=leetcode.com title="Sum of All Odd Length Subarrays"
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for (int len = 1; len <= n; len += 2) {
            for (int i = 0; i + len <= n; i++) {
                for (int j = i; j < i + len; j++) {
                    sum += arr[j];
                }
            }
        }

        return sum;
    }
};
