// @leetcode id=721 questionId=721 slug=accounts-merge lang=cpp site=leetcode.com title="Accounts Merge"
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<string, int> emailToAccount;
        for (int i = 0; i < n; i++) {
            for (size_t j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (emailToAccount.count(email)) {
                    unite(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }

        unordered_map<int, set<string>> groupedEmails;
        for (auto& [email, idx] : emailToAccount) {
            int root = find(idx);
            groupedEmails[root].insert(email);
        }

        vector<vector<string>> result;
        for (auto& [root, emails] : groupedEmails) {
            vector<string> entry;
            entry.push_back(accounts[root][0]);
            for (const string& e : emails) entry.push_back(e);
            result.push_back(entry);
        }
        return result;
    }
};
