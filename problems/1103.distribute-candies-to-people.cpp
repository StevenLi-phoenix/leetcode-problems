// @leetcode id=1103 questionId=1195 slug=distribute-candies-to-people lang=cpp site=leetcode.com title="Distribute Candies to People"
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<long long> result(num_people, 0);
        long long give = 1;
        long long remaining = candies;
        int i = 0;
        while (remaining > 0) {
            long long amount = min(give, remaining);
            result[i] += amount;
            remaining -= amount;
            i = (i + 1) % num_people;
            give++;
        }
        return vector<int>(result.begin(), result.end());
    }
};
