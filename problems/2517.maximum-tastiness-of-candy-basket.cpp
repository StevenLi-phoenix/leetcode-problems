// @leetcode id=2517 questionId=2600 slug=maximum-tastiness-of-candy-basket lang=cpp site=leetcode.com title="Maximum Tastiness of Candy Basket"
class Solution {
public:
    bool canPick(vector<int>& price, int k, int minDiff) {
        int count = 1;
        int last = price[0];
        for (size_t i = 1; i < price.size(); i++) {
            if (price[i] - last >= minDiff) {
                count++;
                last = price[i];
            }
        }
        return count >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int lo = 0, hi = price[n - 1] - price[0];
        int best = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPick(price, k, mid)) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }
};
