// @leetcode id=3045 questionId=3305 slug=count-prefix-and-suffix-pairs-ii lang=cpp site=leetcode.com title="Count Prefix and Suffix Pairs II"
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        // Encode each word as a sequence of (front_char, back_char) pairs
        // walking inward from both ends; a word i is both a prefix and
        // suffix of word j exactly when i's pair-sequence is a prefix of
        // j's pair-sequence. Build a trie over these pair-sequences,
        // querying with each new word before inserting it (to keep i < j).
        vector<unordered_map<int, int>> trie(1);
        vector<int> cnt(1, 0);

        auto newNode = [&]() {
            trie.push_back({});
            cnt.push_back(0);
            return (int)trie.size() - 1;
        };

        long long ans = 0;
        for (auto& word : words) {
            int len = word.size();

            int node = 0;
            long long total = 0;
            for (int i = 0; i < len; i++) {
                int key = (int)(unsigned char)word[i] * 256 + (int)(unsigned char)word[len - 1 - i];
                auto it = trie[node].find(key);
                if (it == trie[node].end()) break;
                node = it->second;
                total += cnt[node];
            }
            ans += total;

            node = 0;
            for (int i = 0; i < len; i++) {
                int key = (int)(unsigned char)word[i] * 256 + (int)(unsigned char)word[len - 1 - i];
                auto it = trie[node].find(key);
                int nxt;
                if (it == trie[node].end()) {
                    nxt = newNode();
                    trie[node][key] = nxt;
                } else {
                    nxt = it->second;
                }
                node = nxt;
            }
            cnt[node]++;
        }
        return ans;
    }
};
