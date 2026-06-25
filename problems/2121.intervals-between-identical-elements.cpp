// @leetcode id=2121 questionId=2240 slug=intervals-between-identical-elements lang=cpp site=leetcode.com title="Intervals Between Identical Elements"
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> result(n, 0);
        unordered_map<int, vector<int>> indexMap;
        
        // Group indices by value
        for (int i = 0; i < n; i++) {
            indexMap[arr[i]].push_back(i);
        }
        
        // For each group, compute the sum of distances using prefix sums
        for (auto& [val, indices] : indexMap) {
            int m = indices.size();
            // prefix[i] = sum of indices[0..i-1]
            long long prefixSum = 0;
            // First pass: left contribution
            // For indices[k], left contribution = indices[k] * k - prefixSum
            vector<long long> leftContrib(m, 0);
            for (int k = 0; k < m; k++) {
                leftContrib[k] = (long long)indices[k] * k - prefixSum;
                prefixSum += indices[k];
            }
            
            long long suffixSum = 0;
            // Second pass: right contribution
            // For indices[k], right contribution = suffixSum - indices[k] * (m - 1 - k)
            for (int k = m - 1; k >= 0; k--) {
                long long rightContrib = suffixSum - (long long)indices[k] * (m - 1 - k);
                result[indices[k]] = leftContrib[k] + rightContrib;
                suffixSum += indices[k];
            }
        }
        
        return result;
    }
};
