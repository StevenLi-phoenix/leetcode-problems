// @leetcode id=315 questionId=315 slug=count-of-smaller-numbers-after-self lang=cpp site=leetcode.com title="Count of Smaller Numbers After Self"
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        function<vector<pair<int, int>>(int, int)> mergeSort = [&](int left, int right) -> vector<pair<int, int>> {
            if (left == right) {
                return {{nums[left], left}};
            }

            int mid = (left + right) / 2;
            auto leftSorted = mergeSort(left, mid);
            auto rightSorted = mergeSort(mid + 1, right);

            vector<pair<int, int>> merged;
            int i = 0, j = 0;

            while (i < leftSorted.size() && j < rightSorted.size()) {
                if (leftSorted[i].first <= rightSorted[j].first) {
                    result[leftSorted[i].second] += j;
                    merged.push_back(leftSorted[i]);
                    i++;
                } else {
                    merged.push_back(rightSorted[j]);
                    j++;
                }
            }

            while (i < leftSorted.size()) {
                result[leftSorted[i].second] += j;
                merged.push_back(leftSorted[i]);
                i++;
            }

            while (j < rightSorted.size()) {
                merged.push_back(rightSorted[j]);
                j++;
            }

            return merged;
        };

        mergeSort(0, n - 1);
        return result;
    }
};
