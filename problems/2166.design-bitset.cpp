// @leetcode id=2166 questionId=2285 slug=design-bitset lang=cpp site=leetcode.com title="Design Bitset"
class Bitset {
    vector<char> bits; // stored bits before applying the global flip
    bool flipped = false;
    int n, cnt = 0; // cnt = number of actual (post-flip) 1-bits

public:
    Bitset(int size) : bits(size, 0), n(size) {}

    void fix(int idx) {
        if ((bits[idx] ^ flipped) == 1) return;
        bits[idx] ^= 1;
        cnt++;
    }

    void unfix(int idx) {
        if ((bits[idx] ^ flipped) == 0) return;
        bits[idx] ^= 1;
        cnt--;
    }

    void flip() {
        flipped = !flipped;
        cnt = n - cnt;
    }

    bool all() {
        return cnt == n;
    }

    bool one() {
        return cnt > 0;
    }

    int count() {
        return cnt;
    }

    string toString() {
        string s(n, '0');
        for (int i = 0; i < n; i++) s[i] = '0' + (bits[i] ^ flipped);
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
