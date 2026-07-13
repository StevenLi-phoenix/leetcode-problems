// @leetcode id=1276 questionId=1401 slug=number-of-burgers-with-no-waste-of-ingredients lang=cpp site=leetcode.com title="Number of Burgers with No Waste of Ingredients"
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // 4j + 2s = tomato, j + s = cheese  =>  j = (tomato - 2*cheese) / 2
        long long diff = (long long)tomatoSlices - 2LL * cheeseSlices;
        if (diff < 0 || diff % 2 != 0) return {};

        long long j = diff / 2;
        long long s = (long long)cheeseSlices - j;
        if (s < 0) return {};

        return {(int)j, (int)s};
    }
};
