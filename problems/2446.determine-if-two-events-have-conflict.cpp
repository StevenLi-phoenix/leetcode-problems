// @leetcode id=2446 questionId=2536 slug=determine-if-two-events-have-conflict lang=cpp site=leetcode.com title="Determine if Two Events Have Conflict"
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return event1[0] <= event2[1] && event2[0] <= event1[1];
    }
};
