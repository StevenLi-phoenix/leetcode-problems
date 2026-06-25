// @leetcode id=1404 questionId=1520 slug=number-of-steps-to-reduce-a-number-in-binary-representation-to-one lang=cpp site=leetcode.com title="Number of Steps to Reduce a Number in Binary Representation to One"
class Solution {
public:
int numSteps(string s) {
int steps = 0;
while (s.size() > 1) {
if (s.back() == '0') {
s.pop_back(); // divide by 2
} else {
// add 1: propagate carry
int i = s.size() - 1;
while (i >= 0 && s[i] == '1') {
s[i] = '0';
i--;
}
if (i >= 0) {
s[i] = '1';
} else {
s = "1" + s;
}
}
steps++;
}
return steps;
}
};
