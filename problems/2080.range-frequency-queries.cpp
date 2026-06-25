// @leetcode id=2080 questionId=1294 slug=range-frequency-queries lang=cpp site=leetcode.com title="Range Frequency Queries"
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> positions;
    
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            positions[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (positions.find(value) == positions.end()) return 0;
        
        const vector<int>& pos = positions[value];
        
        // Find first index >= left
        auto it1 = lower_bound(pos.begin(), pos.end(), left);
        // Find first index > right
        auto it2 = upper_bound(pos.begin(), pos.end(), right);
        
        return (int)(it2 - it1);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
