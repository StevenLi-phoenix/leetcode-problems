// @leetcode id=898 questionId=934 slug=bitwise-ors-of-subarrays lang=cpp site=leetcode.com title="Bitwise ORs of Subarrays"
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> current;
        for (int x : arr) {
            unordered_set<int> next;
            next.insert(x);
            for (int v : current) next.insert(v | x);
            current = next;
            for (int v : current) result.insert(v);
        }
        return result.size();
    }
};
