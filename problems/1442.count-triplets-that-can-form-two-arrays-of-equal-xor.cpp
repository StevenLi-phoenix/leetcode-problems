// @leetcode id=1442 questionId=1553 slug=count-triplets-that-can-form-two-arrays-of-equal-xor lang=cpp site=leetcode.com title="Count Triplets That Can Form Two Arrays of Equal XOR"
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                // XOR from i to k = prefix[k+1] ^ prefix[i]
                if ((prefix[k + 1] ^ prefix[i]) == 0) {
                    count += (k - i); // j can be i+1 to k
                }
            }
        }
        return count;
    }
};
