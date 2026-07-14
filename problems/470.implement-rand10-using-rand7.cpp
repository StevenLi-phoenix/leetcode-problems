// @leetcode id=470 questionId=903 slug=implement-rand10-using-rand7 lang=cpp site=leetcode.com title="Implement Rand10() Using Rand7()"
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int num;
        do {
            num = (rand7() - 1) * 7 + rand7();
        } while (num > 40);
        return (num - 1) % 10 + 1;
    }
};
