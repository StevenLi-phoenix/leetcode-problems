// @leetcode id=2451 questionId=2547 slug=odd-string-difference lang=cpp site=leetcode.com title="Odd String Difference"
class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, vector<int>> diffMap;
        
        for (int i = 0; i < words.size(); i++) {
            string diff = "";
            for (int j = 0; j < words[i].size() - 1; j++) {
                diff += (char)(words[i][j+1] - words[i][j] + 'a');
            }
            diffMap[diff].push_back(i);
        }
        
        for (auto& [diff, indices] : diffMap) {
            if (indices.size() == 1) {
                return words[indices[0]];
            }
        }
        
        return "";
    }
};
