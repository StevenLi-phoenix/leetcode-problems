// @leetcode id=2491 questionId=2581 slug=divide-players-into-teams-of-equal-skill lang=cpp site=leetcode.com title="Divide Players Into Teams of Equal Skill"
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int target = skill[0] + skill[n-1];
        long long chemistry = 0;
        
        for (int i = 0; i < n/2; i++) {
            if (skill[i] + skill[n-1-i] != target) return -1;
            chemistry += (long long)skill[i] * skill[n-1-i];
        }
        
        return chemistry;
    }
};
