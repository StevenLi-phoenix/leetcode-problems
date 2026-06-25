// @leetcode id=1415 questionId=1516 slug=the-k-th-lexicographical-string-of-all-happy-strings-of-length-n lang=cpp site=leetcode.com title="The k-th Lexicographical String of All Happy Strings of Length n"
class Solution {
    public:
    string getHappyString(int n, int k) {
    int total = 3 * (1 << (n - 1));
    if (k > total) return "";
    k--;
    string res;
    int sz = total / 3;
    int idx = k / sz;
    k %= sz;
    res += ('a' + idx);
    for (int i = 1; i < n; i++) {
    sz /= 2;
    int pick = k / sz;
    k %= sz;
    char prev = res.back();
    int cnt = 0;
    for (char c = 'a'; c <= 'c'; c++) {
    if (c != prev) {
    if (cnt == pick) { res += c; break; }
    cnt++;
    }
    }
    }
    return res;
    }
    };
