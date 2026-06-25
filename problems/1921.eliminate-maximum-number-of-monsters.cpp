// @leetcode id=1921 questionId=2049 slug=eliminate-maximum-number-of-monsters lang=cpp site=leetcode.com title="Eliminate Maximum Number of Monsters"
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> arrivalTime(n);
        
        for (int i = 0; i < n; i++) {
            arrivalTime[i] = (double)dist[i] / speed[i];
        }
        
        sort(arrivalTime.begin(), arrivalTime.end());
        
        // At minute i (0-indexed), we can eliminate the i-th monster
        // If the monster arrives at time <= i (i.e., arrivalTime[i] <= i), we lose
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= i) {
                return i;
            }
        }
        
        return n;
    }
};
