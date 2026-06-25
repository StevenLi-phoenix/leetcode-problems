// @leetcode id=857 questionId=887 slug=minimum-cost-to-hire-k-workers lang=cpp site=leetcode.com title="Minimum Cost to Hire K Workers"
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        // Sort by wage/quality ratio
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return (double)wage[a] / quality[a] < (double)wage[b] / quality[b];
        });
        
        priority_queue<int> maxHeap; // max heap of qualities
        int qualitySum = 0;
        double ans = DBL_MAX;
        
        for (int i : idx) {
            maxHeap.push(quality[i]);
            qualitySum += quality[i];
            
            if ((int)maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            
            if ((int)maxHeap.size() == k) {
                double ratio = (double)wage[i] / quality[i];
                ans = min(ans, ratio * qualitySum);
            }
        }
        
        return ans;
    }
};
