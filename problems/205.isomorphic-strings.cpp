// @leetcode id=205 questionId=205 slug=isomorphic-strings lang=cpp site=leetcode.com title="Isomorphic Strings"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> stMap;
        unordered_map<char, char> tsMap;

        for (int i = 0; i < s.length(); i++) {
            char sChar = s[i];
            char tChar = t[i];

            if (stMap.count(sChar)) {
                if (stMap[sChar] != tChar) return false;
            } else {
                stMap[sChar] = tChar;
            }

            if (tsMap.count(tChar)) {
                if (tsMap[tChar] != sChar) return false;
            } else {
                tsMap[tChar] = sChar;
            }
        }

        return true;
    }
};
