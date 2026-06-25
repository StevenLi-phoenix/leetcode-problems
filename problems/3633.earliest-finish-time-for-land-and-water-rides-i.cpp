// @leetcode id=3633 questionId=3965 slug=earliest-finish-time-for-land-and-water-rides-i lang=cpp site=leetcode.com title="Earliest Finish Time for Land and Water Rides I"
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Land ride i first, then water ride j
                int landStart = landStartTime[i];
                int landEnd = landStart + landDuration[i];
                int waterStart = max(landEnd, waterStartTime[j]);
                int waterEnd = waterStart + waterDuration[j];
                ans = min(ans, waterEnd);
                
                // Water ride j first, then land ride i
                int wStart = waterStartTime[j];
                int wEnd = wStart + waterDuration[j];
                int lStart = max(wEnd, landStartTime[i]);
                int lEnd = lStart + landDuration[i];
                ans = min(ans, lEnd);
            }
        }
        
        return ans;
    }
};
