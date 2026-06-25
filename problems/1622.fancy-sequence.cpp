// @leetcode id=1622 questionId=1728 slug=fancy-sequence lang=cpp site=leetcode.com title="Fancy Sequence"
class Fancy {
    static const long long MOD = 1e9 + 7;
    vector<long long> vals;
    long long mul, add;
    long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
    if (exp & 1) res = res * base % mod;
    base = base * base % mod;
    exp >>= 1;
    }
    return res;
    }
    long long inv(long long x) { return power(x, MOD - 2, MOD); }
    public:
    Fancy() : mul(1), add(0) {}
    void append(int val) {
    long long v = ((val - add) % MOD + MOD) % MOD;
    v = v * inv(mul) % MOD;
    vals.push_back(v);
    }
    void addAll(int inc) {
    add = (add + inc) % MOD;
    }
    void multAll(int m) {
    mul = mul * m % MOD;
    add = add * m % MOD;
    }
    int getIndex(int idx) {
    if (idx >= (int)vals.size()) return -1;
    return (vals[idx] * mul % MOD + add) % MOD;
    }
    };
