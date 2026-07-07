// @leetcode id=3913 questionId=4282 slug=sort-vowels-by-frequency lang=cpp site=leetcode.com title="Sort Vowels by Frequency"
class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int freq[26] = {0};
        int firstOcc[26];
        fill(begin(firstOcc), end(firstOcc), INT_MAX);

        vector<int> vowelPositions;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (isVowel(s[i])) {
                int idx = s[i] - 'a';
                ++freq[idx];
                firstOcc[idx] = min(firstOcc[idx], i);
                vowelPositions.push_back(i);
            }
        }

        vector<char> vowelTypes;
        for (char c : {'a', 'e', 'i', 'o', 'u'}) {
            if (freq[c - 'a'] > 0) vowelTypes.push_back(c);
        }
        sort(vowelTypes.begin(), vowelTypes.end(), [&](char a, char b) {
            if (freq[a - 'a'] != freq[b - 'a']) return freq[a - 'a'] > freq[b - 'a'];
            return firstOcc[a - 'a'] < firstOcc[b - 'a'];
        });

        string result = s;
        int pos = 0;
        for (char c : vowelTypes) {
            for (int k = 0; k < freq[c - 'a']; ++k) {
                result[vowelPositions[pos++]] = c;
            }
        }
        return result;
    }
};
