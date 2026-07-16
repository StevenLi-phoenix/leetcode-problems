// @leetcode id=1053 questionId=1139 slug=previous-permutation-with-one-swap lang=cpp site=leetcode.com title="Previous Permutation With One Swap"
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;
        while (i >= 0 && arr[i] <= arr[i + 1]) i--;
        if (i < 0) return arr;

        int bestJ = -1;
        for (int k = i + 1; k < n; k++) {
            if (arr[k] < arr[i]) {
                if (bestJ == -1 || arr[k] > arr[bestJ]) {
                    bestJ = k;
                }
            }
        }

        swap(arr[i], arr[bestJ]);
        return arr;
    }
};
