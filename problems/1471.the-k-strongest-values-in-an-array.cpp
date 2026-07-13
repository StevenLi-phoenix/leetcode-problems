// @leetcode id=1471 questionId=1581 slug=the-k-strongest-values-in-an-array lang=cpp site=leetcode.com title="The k Strongest Values in an Array"
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n - 1) / 2];

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int da = abs(a - m), db = abs(b - m);
            if (da != db) return da > db;
            return a > b;
        });

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
