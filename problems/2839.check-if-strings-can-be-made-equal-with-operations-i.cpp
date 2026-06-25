// @leetcode id=2839 questionId=2999 slug=check-if-strings-can-be-made-equal-with-operations-i lang=cpp site=leetcode.com title="Check if Strings Can be Made Equal With Operations I"
class Solution {
    public:
    bool canBeEqual(string s1, string s2) {
    string e1, e2, o1, o2;
    for (int i = 0; i < 4; i++) {
    if (i % 2 == 0) { e1 += s1[i]; e2 += s2[i]; }
    else { o1 += s1[i]; o2 += s2[i]; }
    }
    sort(e1.begin(), e1.end());
    sort(e2.begin(), e2.end());
    sort(o1.begin(), o1.end());
    sort(o2.begin(), o2.end());
    return e1 == e2 && o1 == o2;
    }
    };
