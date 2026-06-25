// @leetcode id=2784 questionId=2892 slug=check-if-array-is-good lang=cpp site=leetcode.com title="Check if Array is Good"
class Solution {
public:
    bool isGood(vector<int>& nums){
        int n = nums.size() - 1;
        vector<int> count(n + 1, 0);
        for(int x : nums){
            if(x<1||x>n) return false;
            count[x]++;
        }
        for(int i=1;i<n;i++){
            if(count[i] != 1) return false;
        }
        return count[n] == 2;
    }
};
