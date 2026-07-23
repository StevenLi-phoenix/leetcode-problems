// @leetcode id=914 questionId=950 slug=x-of-a-kind-in-a-deck-of-cards lang=cpp site=leetcode.com title="X of a Kind in a Deck of Cards"
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int x : deck) freq[x]++;

        int g = 0;
        for (auto& [val, count] : freq) {
            g = __gcd(g, count);
        }
        return g >= 2;
    }
};
