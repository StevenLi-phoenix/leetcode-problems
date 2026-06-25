// @leetcode id=3492 questionId=3817 slug=maximum-containers-on-a-ship lang=cpp site=leetcode.com title="Maximum Containers on a Ship"
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        long long totalCells = (long long)n * n;
        long long maxContainersWeight = maxWeight / w;
        return min(totalCells, maxContainersWeight);
    }
};
