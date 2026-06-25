// @leetcode id=599 questionId=599 slug=minimum-index-sum-of-two-lists lang=cpp site=leetcode.com title="Minimum Index Sum of Two Lists"
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> idx1;
        for (int i = 0; i < (int)list1.size(); i++) {
            idx1[list1[i]] = i;
        }
        
        vector<string> result;
        int minSum = INT_MAX;
        
        for (int j = 0; j < (int)list2.size(); j++) {
            auto it = idx1.find(list2[j]);
            if (it != idx1.end()) {
                int sum = it->second + j;
                if (sum < minSum) {
                    minSum = sum;
                    result = {list2[j]};
                } else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};
