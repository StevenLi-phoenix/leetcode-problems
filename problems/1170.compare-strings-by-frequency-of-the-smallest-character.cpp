// @leetcode id=1170 questionId=1273 slug=compare-strings-by-frequency-of-the-smallest-character lang=cpp site=leetcode.com title="Compare Strings by Frequency of the Smallest Character"
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [](const string& s) {
            char smallest = *min_element(s.begin(), s.end());
            return count(s.begin(), s.end(), smallest);
        };

        vector<int> wordFreqs;
        for (auto& w : words) wordFreqs.push_back(f(w));
        sort(wordFreqs.begin(), wordFreqs.end());

        vector<int> result;
        for (auto& q : queries) {
            int qf = f(q);
            int idx = upper_bound(wordFreqs.begin(), wordFreqs.end(), qf) - wordFreqs.begin();
            result.push_back(wordFreqs.size() - idx);
        }
        return result;
    }
};
