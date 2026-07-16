// @leetcode id=969 questionId=1009 slug=pancake-sorting lang=cpp site=leetcode.com title="Pancake Sorting"
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        for (int size = n; size >= 2; size--) {
            int maxIdx = 0;
            for (int i = 1; i < size; i++) {
                if (arr[i] > arr[maxIdx]) maxIdx = i;
            }
            if (maxIdx == size - 1) continue;
            if (maxIdx != 0) {
                reverse(arr.begin(), arr.begin() + maxIdx + 1);
                result.push_back(maxIdx + 1);
            }
            reverse(arr.begin(), arr.begin() + size);
            result.push_back(size);
        }
        return result;
    }
};
