// @leetcode id=1461 questionId=1557 slug=check-if-a-string-contains-all-binary-codes-of-size-k lang=cpp site=leetcode.com title="Check If a String Contains All Binary Codes of Size K"
class Solution {
public:
bool hasAllCodes(string s, int k) {
if ((int)s.size() < k) return false;
unordered_set<string> seen;
for (int i = 0; i <= (int)s.size() - k; i++) {
seen.insert(s.substr(i, k));
}
return (int)seen.size() == (1 << k);
}
};
