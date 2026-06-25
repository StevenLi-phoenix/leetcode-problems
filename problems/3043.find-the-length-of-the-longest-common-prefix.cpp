// @leetcode id=3043 questionId=3329 slug=find-the-length-of-the-longest-common-prefix lang=cpp site=leetcode.com title="Find the Length of the Longest Common Prefix"
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixSet;
        
        // Insert all prefixes of arr1 elements into the set
        for (int num : arr1) {
            while (num > 0) {
                prefixSet.insert(num);
                num /= 10;
            }
        }
        
        int maxLen = 0;
        
        // Check all prefixes of arr2 elements against the set
        for (int num : arr2) {
            while (num > 0) {
                if (prefixSet.count(num)) {
                    // Count digits of num
                    int len = to_string(num).length();
                    maxLen = max(maxLen, (int)len);
                }
                num /= 10;
            }
        }
        
        return maxLen;
    }
};
