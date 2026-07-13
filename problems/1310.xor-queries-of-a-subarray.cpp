// @leetcode id=1310 questionId=1435 slug=xor-queries-of-a-subarray lang=cpp site=leetcode.com title="XOR Queries of a Subarray"
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] ^ arr[i];

        vector<int> result;
        for (auto& q : queries) {
            result.push_back(prefix[q[0]] ^ prefix[q[1] + 1]);
        }
        return result;
    }
};
