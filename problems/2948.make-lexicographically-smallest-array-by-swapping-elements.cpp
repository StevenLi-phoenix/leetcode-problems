// @leetcode id=2948 questionId=3219 slug=make-lexicographically-smallest-array-by-swapping-elements lang=cpp site=leetcode.com title="Make Lexicographically Smallest Array by Swapping Elements"
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Create (value, index) pairs and sort by value
        vector<pair<int,int>> sorted_nums;
        for (int i = 0; i < n; i++) sorted_nums.push_back({nums[i], i});
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> result(n);
        
        int i = 0;
        while (i < n) {
            // Find the end of the current component
            int j = i + 1;
            while (j < n && sorted_nums[j].first - sorted_nums[j-1].first <= limit) j++;
            
            // Component: sorted_nums[i..j-1]
            // Collect indices in this component and sort them
            vector<int> indices;
            for (int k = i; k < j; k++) indices.push_back(sorted_nums[k].second);
            sort(indices.begin(), indices.end());
            
            // Assign sorted values to sorted indices
            for (int k = 0; k < (int)indices.size(); k++) {
                result[indices[k]] = sorted_nums[i + k].first;
            }
            
            i = j;
        }
        
        return result;
    }
};
