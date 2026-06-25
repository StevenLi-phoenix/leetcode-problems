// @leetcode id=3869 questionId=4159 slug=count-fancy-numbers-in-a-range lang=cpp site=leetcode.com title="Count Fancy Numbers in a Range"
class Solution {
public:
    bool isGood(long long n) {
        if (n < 10) return true;
        string s = to_string(n);
        bool inc = true, dec = true;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] <= s[i-1]) inc = false;
            if (s[i] >= s[i-1]) dec = false;
        }
        return inc || dec;
    }
    
    map<pair<int,int>, long long> waysCache;
    long long countWays(int remaining, int S) {
        if (remaining == 0) return S == 0 ? 1 : 0;
        if (S < 0 || S > 9 * remaining) return 0;
        auto key = make_pair(remaining, S);
        auto it = waysCache.find(key);
        if (it != waysCache.end()) return it->second;
        long long res = 0;
        for (int d = 0; d <= 9; d++) res += countWays(remaining - 1, S - d);
        return waysCache[key] = res;
    }
    
    long long countFancy(long long l, long long r) {
        vector<long long> goods;
        
        for (int mask = 1; mask < (1 << 10); mask++) {
            vector<int> digits;
            for (int d = 0; d <= 9; d++)
                if (mask & (1 << d)) digits.push_back(d);
            if (digits[0] == 0) continue;
            long long num = 0;
            for (int d : digits) num = num * 10 + d;
            if (num >= 1 && num <= (long long)1e15) goods.push_back(num);
        }
        
        for (int mask = 1; mask < (1 << 10); mask++) {
            vector<int> digits;
            for (int d = 9; d >= 0; d--)
                if (mask & (1 << d)) digits.push_back(d);
            if (digits[0] == 0) continue;
            long long num = 0;
            for (int d : digits) num = num * 10 + d;
            if (num >= 1 && num <= (long long)1e15) goods.push_back(num);
        }
        
        sort(goods.begin(), goods.end());
        goods.erase(unique(goods.begin(), goods.end()), goods.end());
        
        set<int> goodSums;
        for (int s = 1; s <= 144; s++)
            if (isGood(s)) goodSums.insert(s);
        
        // Digit DP: count numbers in [1, bound] with digit_sum in goodSums
        auto cnt = [&](long long bound) -> long long {
            if (bound <= 0) return 0;
            string s = to_string(bound);
            int n = s.size();
            long long result = 0;
            
            // Count all k-digit numbers (k < n) with digit_sum in goodSums
            for (int k = 1; k < n; k++) {
                // First digit: 1-9, remaining k-1 digits: 0-9
                for (int first = 1; first <= 9; first++) {
                    for (int target : goodSums) {
                        int S = target - first;
                        result += countWays(k - 1, S);
                    }
                }
            }
            
            // Count n-digit numbers <= bound with digit_sum in goodSums
            int curSum = 0;
            for (int i = 0; i < n; i++) {
                int d = s[i] - '0';
                int startDigit = (i == 0) ? 1 : 0;
                for (int x = startDigit; x < d; x++) {
                    int rem = n - i - 1;
                    int fixed = curSum + x;
                    if (rem == 0) {
                        if (fixed >= 1 && goodSums.count(fixed)) result++;
                    } else {
                        for (int target : goodSums) {
                            result += countWays(rem, target - fixed);
                        }
                    }
                }
                curSum += d;
                if (i == n - 1) {
                    if (curSum >= 1 && goodSums.count(curSum)) result++;
                }
            }
            return result;
        };
        
        long long goodsCnt = (long long)(upper_bound(goods.begin(), goods.end(), r) - 
                                          upper_bound(goods.begin(), goods.end(), l - 1));
        
        long long overlap = 0;
        for (long long g : goods) {
            if (g < l || g > r) continue;
            long long tmp = g;
            int dsum = 0;
            while (tmp > 0) { dsum += tmp % 10; tmp /= 10; }
            if (goodSums.count(dsum)) overlap++;
        }
        
        return cnt(r) - cnt(l - 1) + goodsCnt - overlap;
    }
};
