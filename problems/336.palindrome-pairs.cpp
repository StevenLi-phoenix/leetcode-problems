// @leetcode id=336 questionId=336 slug=palindrome-pairs lang=cpp site=leetcode.com title="Palindrome Pairs"
class Solution {
public:
    bool isPalindrome(const string& s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo] != s[hi]) return false;
            lo++; hi--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> indexOf;
        int n = words.size();
        for (int i = 0; i < n; i++) indexOf[words[i]] = i;

        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            string& w = words[i];
            int len = w.size();

            for (int cut = 0; cut <= len; cut++) {
                // split w into w[0..cut) and w[cut..len)
                // Case A: w[0..cut) is palindrome -> need reverse(w[cut..len)) as another word, placed before w
                if (isPalindrome(w, 0, cut - 1)) {
                    string suffix = w.substr(cut);
                    string revSuffix = suffix;
                    reverse(revSuffix.begin(), revSuffix.end());
                    auto it = indexOf.find(revSuffix);
                    if (it != indexOf.end() && it->second != i) {
                        result.push_back({it->second, i});
                    }
                }
                // Case B: w[cut..len) is palindrome -> need reverse(w[0..cut)) as another word, placed after w
                // avoid double-counting cut==len with case A handled by boundary check below
                if (cut != len && isPalindrome(w, cut, len - 1)) {
                    string prefix = w.substr(0, cut);
                    string revPrefix = prefix;
                    reverse(revPrefix.begin(), revPrefix.end());
                    auto it = indexOf.find(revPrefix);
                    if (it != indexOf.end() && it->second != i) {
                        result.push_back({i, it->second});
                    }
                }
            }
        }

        return result;
    }
};
