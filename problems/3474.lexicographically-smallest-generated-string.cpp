// @leetcode id=3474 questionId=3770 slug=lexicographically-smallest-generated-string lang=cpp site=leetcode.com title="Lexicographically Smallest Generated String"
class Solution {
    public:
    string generateString(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    int len = n + m - 1;
    string word(len, 'a');
    // forced[i] = true means position i was set by a T constraint
    vector<bool> forced(len, false);
    // Apply T constraints
    for (int i = 0; i < n; i++) {
    if (str1[i] == 'T') {
    for (int j = 0; j < m; j++) {
    if (forced[i+j] && word[i+j] != str2[j]) return "";
    word[i+j] = str2[j];
    forced[i+j] = true;
    }
    }
    }
    // Handle F constraints
    for (int i = 0; i < n; i++) {
    if (str1[i] == 'F') {
    // Check if word[i..i+m-1] == str2
    bool eq = true;
    for (int j = 0; j < m; j++) {
    if (word[i+j] != str2[j]) { eq = false; break; }
    }
    if (eq) {
    // Need to change one char at a non-forced position
    // Try to change last position first (to keep lex smallest)
    bool changed = false;
    for (int j = m-1; j >= 0; j--) {
    if (!forced[i+j]) {
    // Change to smallest char != str2[j]
    char c = (str2[j] == 'a') ? 'b' : 'a';
    word[i+j] = c;
    changed = true;
    break;
    }
    }
    if (!changed) return "";
    }
    }
    }
    // Verify all T constraints
    for (int i = 0; i < n; i++) {
    if (str1[i] == 'T') {
    for (int j = 0; j < m; j++) {
    if (word[i+j] != str2[j]) return "";
    }
    }
    }
    // Verify all F constraints
    for (int i = 0; i < n; i++) {
    if (str1[i] == 'F') {
    bool eq = true;
    for (int j = 0; j < m; j++) {
    if (word[i+j] != str2[j]) { eq = false; break; }
    }
    if (eq) return "";
    }
    }
    return word;
    }
    };
