// @leetcode id=1962 questionId=2094 slug=remove-stones-to-minimize-the-total lang=cpp site=leetcode.com title="Remove Stones to Minimize the Total"
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Max heap
        priority_queue<int> pq(piles.begin(), piles.end());
        
        for (int i = 0; i < k; i++) {
            int top = pq.top(); pq.pop();
            top = top - top / 2; // Remove floor(top/2) stones
            pq.push(top);
        }
        
        int total = 0;
        while (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};
