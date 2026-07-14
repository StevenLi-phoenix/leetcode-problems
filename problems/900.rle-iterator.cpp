// @leetcode id=900 questionId=936 slug=rle-iterator lang=cpp site=leetcode.com title="RLE Iterator"
class RLEIterator {
public:
    vector<int> enc;
    int idx = 0;

    RLEIterator(vector<int>& encoding) {
        enc = encoding;
    }

    int next(int n) {
        while (idx < (int)enc.size()) {
            if (enc[idx] >= n) {
                enc[idx] -= n;
                return enc[idx + 1];
            }
            n -= enc[idx];
            idx += 2;
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
