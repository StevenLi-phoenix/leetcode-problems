// @leetcode id=287 questionId=287 slug=find-the-duplicate-number lang=cpp site=leetcode.com title="Find the Duplicate Number"
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd's cycle detection
        // Treat as linked list: i -> nums[i]
        // Duplicate means cycle exists, cycle entry = duplicate
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        // Phase 1: find meeting point inside cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // Phase 2: find cycle entry (= duplicate)
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
