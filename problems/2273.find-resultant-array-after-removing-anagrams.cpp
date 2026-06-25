// @leetcode id=2273 questionId=1353 slug=find-resultant-array-after-removing-anagrams lang=cpp site=leetcode.com title="Find Resultant Array After Removing Anagrams"
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        for (const string& w : words) {
            if (!res.empty()) {
                string a = res.back(), b = w;
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                if (a == b) continue;
            }
            res.push_back(w);
        }
        return res;
    }
};
