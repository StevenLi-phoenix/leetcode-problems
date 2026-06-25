// @leetcode id=457 questionId=457 slug=circular-array-loop lang=cpp site=leetcode.com title="Circular Array Loop"
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        auto next = [&](int i) {
            return ((i + nums[i]) % n + n) % n;
        };
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            
            // Slow and fast pointers
            int slow = i, fast = i;
            
            // Check all elements have same sign
            while (true) {
                int nSlow = next(slow);
                int nFast = next(fast);
                int nFast2 = next(nFast);
                
                // Check same direction
                if (nums[slow] * nums[nSlow] <= 0) break;
                if (nums[fast] * nums[nFast] <= 0) break;
                if (nums[nFast] * nums[nFast2] <= 0) break;
                
                slow = nSlow;
                fast = nFast2;
                
                if (slow == fast) {
                    // Check cycle length > 1 (not single element loop)
                    if (slow == next(slow)) break;
                    return true;
                }
            }
            
            // Mark visited elements with 0 to avoid revisiting
            slow = i;
            while (nums[slow] != 0 && nums[slow] * nums[next(slow)] > 0) {
                int tmp = next(slow);
                nums[slow] = 0;
                slow = tmp;
            }
        }
        
        return false;
    }
};
