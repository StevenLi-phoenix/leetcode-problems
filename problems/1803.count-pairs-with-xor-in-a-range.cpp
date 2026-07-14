// @leetcode id=1803 questionId=1907 slug=count-pairs-with-xor-in-a-range lang=cpp site=leetcode.com title="Count Pairs With XOR in a Range"
class Solution {
public:
    static const int BITS = 14; // values fit in 15 bits (< 2^15)
    vector<array<int, 2>> children;
    vector<int> count;

    void init() {
        children.clear();
        count.clear();
        children.push_back({-1, -1});
        count.push_back(0);
    }

    int newNode() {
        children.push_back({-1, -1});
        count.push_back(0);
        return children.size() - 1;
    }

    void insert(int x) {
        int node = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (children[node][bit] == -1) children[node][bit] = newNode();
            node = children[node][bit];
            count[node]++;
        }
    }

    // Number of previously inserted values y such that (x XOR y) < limit.
    int countLessThan(int x, int limit) {
        if (limit <= 0) return 0;
        int node = 0, total = 0;
        for (int b = BITS; b >= 0 && node != -1; b--) {
            int xBit = (x >> b) & 1;
            int limBit = (limit >> b) & 1;
            if (limBit == 1) {
                // Taking the branch where xor-bit == xBit (same as x's bit,
                // giving xor bit 0) keeps us strictly under limit for this
                // position; add all values in that branch, then continue
                // down the branch matching limit's bit (xor bit 1).
                int sameBranch = children[node][xBit];
                if (sameBranch != -1) total += count[sameBranch];
                node = children[node][1 - xBit];
            } else {
                node = children[node][xBit];
            }
        }
        return total;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        init();
        int total = 0;
        for (int x : nums) {
            total += countLessThan(x, high + 1) - countLessThan(x, low);
            insert(x);
        }
        return total;
    }
};
