// @leetcode id=2452 questionId=2550 slug=words-within-two-edits-of-dictionary lang=cpp site=leetcode.com title="Words Within Two Edits of Dictionary"
class Solution {
    public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> result;
    for (auto& q : queries) {
    for (auto& d : dictionary) {
    int diff = 0;
    for (int i = 0; i < q.size(); i++) {
    if (q[i] != d[i]) diff++;
    }
    if (diff <= 2) {
    result.push_back(q);
    break;
    }
    }
    }
    return result;
    }
    };
