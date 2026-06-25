// @leetcode id=2591 questionId=2663 slug=distribute-money-to-maximum-children lang=cpp site=leetcode.com title="Distribute Money to Maximum Children"
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;

        int k = min(money / 8, children);

        for (int i = k; i >= 0; i--) {
            int remaining = money - 8 * i;
            int remaining_children = children - i;

            if (remaining_children == 0) {
                if (remaining == 0) return i;
            } else if (remaining_children == 1) {
                if (remaining != 4 && remaining >= 1) return i;
            } else {
                if (remaining >= remaining_children) return i;
            }
        }

        return -1;
    }
};
