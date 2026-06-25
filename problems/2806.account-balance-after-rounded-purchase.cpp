// @leetcode id=2806 questionId=2955 slug=account-balance-after-rounded-purchase lang=cpp site=leetcode.com title="Account Balance After Rounded Purchase"
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rounded = ((purchaseAmount + 5) / 10) * 10;
        return 100 - rounded;
    }
};
