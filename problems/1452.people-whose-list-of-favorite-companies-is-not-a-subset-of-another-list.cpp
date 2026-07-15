// @leetcode id=1452 questionId=1562 slug=people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list lang=cpp site=leetcode.com title="People Whose List of Favorite Companies Is Not a Subset of Another List"
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        vector<unordered_set<string>> sets(n);
        for (int i = 0; i < n; i++) {
            sets[i] = unordered_set<string>(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            bool isSubset = false;
            for (int j = 0; j < n && !isSubset; j++) {
                if (i == j || sets[j].size() < sets[i].size()) continue;
                bool allFound = true;
                for (const string& c : favoriteCompanies[i]) {
                    if (!sets[j].count(c)) { allFound = false; break; }
                }
                if (allFound) isSubset = true;
            }
            if (!isSubset) result.push_back(i);
        }
        return result;
    }
};
