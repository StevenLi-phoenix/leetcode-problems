// @leetcode id=3777 questionId=4064 slug=minimum-deletions-to-make-alternating-substring lang=cpp site=leetcode.com title="Minimum Deletions to Make Alternating Substring"
class Solution {
public:
    vector<int> bit;
    int bitN;

    void update(int pos, int delta) {
        for (pos++; pos <= bitN; pos += pos & (-pos)) bit[pos] += delta;
    }

    int query(int pos) { // prefix sum [0..pos]
        if (pos < 0) return 0;
        int res = 0;
        for (pos++; pos > 0; pos -= pos & (-pos)) res += bit[pos];
        return res;
    }

    int rangeQuery(int l, int r) { // sum over [l..r]
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }

    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        bitN = max(n - 1, 1);
        bit.assign(bitN + 1, 0);

        auto isEqual = [&](int i) { return s[i] == s[i + 1] ? 1 : 0; };

        for (int i = 0; i + 1 < n; i++) {
            if (isEqual(i)) update(i, 1);
        }

        vector<int> answer;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int j = q[1];
                int beforeLeft = (j - 1 >= 0) ? isEqual(j - 1) : 0;
                int beforeRight = (j + 1 < n) ? isEqual(j) : 0;

                s[j] = (s[j] == 'A') ? 'B' : 'A';

                if (j - 1 >= 0) {
                    int afterLeft = isEqual(j - 1);
                    if (afterLeft != beforeLeft) update(j - 1, afterLeft - beforeLeft);
                }
                if (j + 1 < n) {
                    int afterRight = isEqual(j);
                    if (afterRight != beforeRight) update(j, afterRight - beforeRight);
                }
            } else {
                int l = q[1], r = q[2];
                answer.push_back(rangeQuery(l, r - 1));
            }
        }

        return answer;
    }
};
