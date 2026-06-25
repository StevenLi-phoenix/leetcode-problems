// @leetcode id=1356 questionId=1458 slug=sort-integers-by-the-number-of-1-bits lang=cpp site=leetcode.com title="Sort Integers by The Number of 1 Bits"
class Solution {
public:
vector<int> sortByBits(vector<int>& arr) {
sort(arr.begin(), arr.end(), [](int a, int b) {
int ca = __builtin_popcount(a), cb = __builtin_popcount(b);
if (ca != cb) return ca < cb;
return a < b;
});
return arr;
}
};
