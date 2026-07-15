// @leetcode id=3457 questionId=3779 slug=eat-pizzas lang=cpp site=leetcode.com title="Eat Pizzas!"
class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end(), greater<int>());
        int n = pizzas.size();
        int days = n / 4;

        int oddDays = (days + 1) / 2;
        int evenDays = days / 2;

        long long sum = 0;
        int i = 0, j = n - 1;
        for (int k = 0; k < oddDays; k++) {
            sum += pizzas[i];
            i++;
            j -= 3;
        }
        for (int k = 0; k < evenDays; k++) {
            i++; // unscored filler, larger than the Y about to be picked
            sum += pizzas[i];
            i++;
            j -= 2;
        }
        return sum;
    }
};
