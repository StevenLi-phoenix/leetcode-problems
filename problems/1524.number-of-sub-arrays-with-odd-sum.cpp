// @leetcode id=1524 questionId=1631 slug=number-of-sub-arrays-with-odd-sum lang=cpp site=leetcode.com title="Number of Sub-arrays With Odd Sum"
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1e9 + 7;
        long long evenCount = 1, oddCount = 0;
        long long prefix = 0;
        long long result = 0;
        for (int x : arr) {
            prefix += x;
            if (prefix % 2 == 0) {
                result = (result + oddCount) % MOD;
                evenCount++;
            } else {
                result = (result + evenCount) % MOD;
                oddCount++;
            }
        }
        return (int)result;
    }
};
