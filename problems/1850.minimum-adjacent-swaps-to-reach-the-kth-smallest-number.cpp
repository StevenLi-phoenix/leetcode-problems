// @leetcode id=1850 questionId=1978 slug=minimum-adjacent-swaps-to-reach-the-kth-smallest-number lang=cpp site=leetcode.com title="Minimum Adjacent Swaps to Reach the Kth Smallest Number"
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string original = num;
        // Find the kth next permutation
        for (int i = 0; i < k; i++) {
            next_permutation(num.begin(), num.end());
        }
        // Count minimum adjacent swaps to convert original to num
        int swaps = 0;
        string s = original;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != num[i]) {
                // Find the position of num[i] in s starting from i+1
                int j = i + 1;
                while (s[j] != num[i]) j++;
                // Swap s[j] towards s[i]
                while (j > i) {
                    swap(s[j], s[j-1]);
                    j--;
                    swaps++;
                }
            }
        }
        return swaps;
    }
};
