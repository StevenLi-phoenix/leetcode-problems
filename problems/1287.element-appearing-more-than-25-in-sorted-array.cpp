// @leetcode id=1287 questionId=1221 slug=element-appearing-more-than-25-in-sorted-array lang=cpp site=leetcode.com title="Element Appearing More Than 25% In Sorted Array"
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> positions = {n/4, n/2, 3*n/4, n-1};

        for (int pos : positions) {
            int val = arr[pos];
            int count = 0;
            for (int x : arr) {
                if (x == val) count++;
            }
            if (count * 4 > n) {
                return val;
            }
        }

        return -1;
    }
};
