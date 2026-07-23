// @leetcode id=1122 questionId=1217 slug=relative-sort-array lang=cpp site=leetcode.com title="Relative Sort Array"
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001] = {0};
        for (int x : arr1) count[x]++;

        vector<int> result;
        for (int x : arr2) {
            while (count[x] > 0) {
                result.push_back(x);
                count[x]--;
            }
        }
        for (int x = 0; x <= 1000; x++) {
            while (count[x] > 0) {
                result.push_back(x);
                count[x]--;
            }
        }
        return result;
    }
};
