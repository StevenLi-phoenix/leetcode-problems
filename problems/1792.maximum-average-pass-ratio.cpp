// @leetcode id=1792 questionId=1917 slug=maximum-average-pass-ratio lang=cpp site=leetcode.com title="Maximum Average Pass Ratio"
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // gain of adding 1 student: (p+1)/(t+1) - p/t
        auto gain = [](long long p, long long t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };
        
        // Max heap: (gain, pass, total)
        priority_queue<pair<double, pair<int,int>>> pq;
        
        for (auto& c : classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), {p, t}});
        }
        
        for (int i = 0; i < extraStudents; i++) {
            auto [g, pt] = pq.top(); pq.pop();
            auto [p, t] = pt;
            p++; t++;
            pq.push({gain(p, t), {p, t}});
        }
        
        double total = 0;
        int n = pq.size();
        while (!pq.empty()) {
            auto [g, pt] = pq.top(); pq.pop();
            total += (double)pt.first / pt.second;
        }
        
        return total / n;
    }
};
