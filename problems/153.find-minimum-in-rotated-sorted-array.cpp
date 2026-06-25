// @leetcode id=153 questionId=153 slug=find-minimum-in-rotated-sorted-array lang=cpp site=leetcode.com title="Find Minimum in Rotated Sorted Array"
class Solution{
public:
    int findMin(vector<int>& nums){
        int lo=0, hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid;
        }
        return nums[lo];
    }
};
