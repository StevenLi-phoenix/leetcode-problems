// @leetcode id=388 questionId=388 slug=longest-absolute-file-path lang=cpp site=leetcode.com title="Longest Absolute File Path"
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> pathLen; // pathLen[d] = cumulative length up to depth d (including separators)
        int maxLen = 0;
        int i = 0;
        int n = input.size();
        while (i < n) {
            int depth = 0;
            while (i < n && input[i] == '\t') { depth++; i++; }
            int start = i;
            while (i < n && input[i] != '\n') i++;
            string name = input.substr(start, i - start);
            if (i < n) i++; // skip '\n'

            if ((int)pathLen.size() > depth) pathLen.resize(depth);
            int base = pathLen.empty() ? 0 : pathLen.back();
            int curLen = base + (int)name.size() + (base > 0 ? 1 : 0);
            pathLen.push_back(curLen);

            if (name.find('.') != string::npos) {
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};
