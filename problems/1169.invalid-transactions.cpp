// @leetcode id=1169 questionId=1272 slug=invalid-transactions lang=cpp site=leetcode.com title="Invalid Transactions"
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> name(n), city(n);
        vector<int> time(n), amount(n);

        for (int i = 0; i < n; i++) {
            string& t = transactions[i];
            int p1 = t.find(',');
            int p2 = t.find(',', p1 + 1);
            int p3 = t.find(',', p2 + 1);
            name[i] = t.substr(0, p1);
            time[i] = stoi(t.substr(p1 + 1, p2 - p1 - 1));
            amount[i] = stoi(t.substr(p2 + 1, p3 - p2 - 1));
            city[i] = t.substr(p3 + 1);
        }

        vector<bool> invalid(n, false);
        for (int i = 0; i < n; i++) {
            if (amount[i] > 1000) invalid[i] = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (name[i] == name[j] && city[i] != city[j] && abs(time[i] - time[j]) <= 60) {
                    invalid[i] = true;
                    break;
                }
            }
        }

        vector<string> result;
        for (int i = 0; i < n; i++) if (invalid[i]) result.push_back(transactions[i]);
        return result;
    }
};
