// @leetcode id=2053 questionId=2163 slug=kth-distinct-string-in-an-array lang=cpp site=leetcode.com title="Kth Distinct String in an Array"
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for (auto& s : arr) {
            count[s]++;
        }
        int distinct = 0;
        for (auto& s : arr) {
            if (count[s] == 1) {
                distinct++;
                if (distinct == k) return s;
            }
        }
        return "";
    }
};
