// @leetcode id=1753 questionId=1879 slug=maximum-score-from-removing-stones lang=cpp site=leetcode.com title="Maximum Score From Removing Stones"
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // Sort so a <= b <= c
        int arr[3] = {a, b, c};
        sort(arr, arr + 3);
        // If largest pile > sum of other two, answer is sum of other two
        if (arr[2] >= arr[0] + arr[1]) {
            return arr[0] + arr[1];
        }
        // Otherwise all stones can be paired optimally
        return (arr[0] + arr[1] + arr[2]) / 2;
    }
};
