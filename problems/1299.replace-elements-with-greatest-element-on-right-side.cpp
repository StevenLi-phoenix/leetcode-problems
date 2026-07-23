// @leetcode id=1299 questionId=1231 slug=replace-elements-with-greatest-element-on-right-side lang=cpp site=leetcode.com title="Replace Elements with Greatest Element on Right Side"
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = -1;
        for (int i = n - 1; i >= 0; i--) {
            int cur = arr[i];
            arr[i] = maxRight;
            maxRight = max(maxRight, cur);
        }
        return arr;
    }
};
