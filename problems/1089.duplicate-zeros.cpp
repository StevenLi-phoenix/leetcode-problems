// @leetcode id=1089 questionId=1168 slug=duplicate-zeros lang=cpp site=leetcode.com title="Duplicate Zeros"
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> copy = arr;
        int j = 0;
        for (int i = 0; i < n && j < n; i++, j++) {
            arr[j] = copy[i];
            if (copy[i] == 0 && j + 1 < n) {
                j++;
                arr[j] = 0;
            }
        }
    }
};
