// @leetcode id=519 questionId=913 slug=random-flip-matrix lang=cpp site=leetcode.com title="Random Flip Matrix"
class Solution {
public:
    Solution(int m, int n) : rows(m), cols(n), total((long long)m * n) {
    }

    vector<int> flip() {
        long long idx = rand() % total;
        long long actual = mapping.count(idx) ? mapping[idx] : idx;

        long long last = total - 1;
        mapping[idx] = mapping.count(last) ? mapping[last] : last;
        mapping.erase(last);
        total--;

        return {(int)(actual / cols), (int)(actual % cols)};
    }

    void reset() {
        total = (long long)rows * cols;
        mapping.clear();
    }

private:
    int rows, cols;
    long long total;
    unordered_map<long long, long long> mapping;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
