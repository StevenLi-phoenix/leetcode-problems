// @leetcode id=3816 questionId=4086 slug=lexicographically-smallest-string-after-deleting-duplicate-characters lang=cpp site=leetcode.com title="Lexicographically Smallest String After Deleting Duplicate Characters"
class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        // Each letter may keep any nonempty subset of its occurrences (in
        // order), not just exactly one — so unlike the classic "remove
        // duplicate letters" problem, keeping an extra duplicate can help
        // (e.g. "aab" beats "ab" since delaying a larger char is good).
        // Monotonic stack: pop a larger, safely-droppable top, then always
        // push the current char. A final tail-trim removes any trailing
        // characters that are pure duplicates of something earlier in the
        // stack (safe: a proper prefix is never lexicographically larger).
        int remaining[26] = {};
        for (char c : s) remaining[c - 'a']++;

        string stack;
        int inStack[26] = {};
        for (char c : s) {
            int ci = c - 'a';
            remaining[ci]--; // after this index, this many occurrences of c are left
            while (!stack.empty() && stack.back() > c) {
                int ti = stack.back() - 'a';
                if (inStack[ti] > 1 || remaining[ti] > 0) {
                    inStack[ti]--;
                    stack.pop_back();
                } else break;
            }
            stack += c;
            inStack[ci]++;
        }

        while (!stack.empty() && inStack[stack.back() - 'a'] > 1) {
            inStack[stack.back() - 'a']--;
            stack.pop_back();
        }
        return stack;
    }
};
