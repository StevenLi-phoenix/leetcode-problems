// @leetcode id=767 questionId=778 slug=reorganize-string lang=cpp site=leetcode.com title="Reorganize String"
class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) maxHeap.push({freq[i], 'a' + i});
        }

        string result;
        while (maxHeap.size() >= 2) {
            auto [count1, c1] = maxHeap.top(); maxHeap.pop();
            auto [count2, c2] = maxHeap.top(); maxHeap.pop();
            result += c1;
            result += c2;
            if (count1 - 1 > 0) maxHeap.push({count1 - 1, c1});
            if (count2 - 1 > 0) maxHeap.push({count2 - 1, c2});
        }

        if (!maxHeap.empty()) {
            auto [count, c] = maxHeap.top();
            if (count > 1) return "";
            result += c;
        }
        return result;
    }
};
