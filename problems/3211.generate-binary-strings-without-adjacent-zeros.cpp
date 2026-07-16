// @leetcode id=3211 questionId=3453 slug=generate-binary-strings-without-adjacent-zeros lang=cpp site=leetcode.com title="Generate Binary Strings Without Adjacent Zeros"
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string cur;
        backtrack(n, cur, result);
        return result;
    }

private:
    void backtrack(int n, string& cur, vector<string>& result) {
        if ((int)cur.size() == n) {
            result.push_back(cur);
            return;
        }
        cur.push_back('1');
        backtrack(n, cur, result);
        cur.pop_back();

        if (cur.empty() || cur.back() == '1') {
            cur.push_back('0');
            backtrack(n, cur, result);
            cur.pop_back();
        }
    }
};
