// @leetcode id=1409 questionId=1525 slug=queries-on-a-permutation-with-key lang=cpp site=leetcode.com title="Queries on a Permutation With Key"
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P;
        for (int i = 1; i <= m; i++) P.push_back(i);
        
        vector<int> result;
        for (int q : queries) {
            // Find position of q in P
            int pos = -1;
            for (int i = 0; i < (int)P.size(); i++) {
                if (P[i] == q) {
                    pos = i;
                    break;
                }
            }
            result.push_back(pos);
            // Move q to the beginning
            P.erase(P.begin() + pos);
            P.insert(P.begin(), q);
        }
        return result;
    }
};
