// @leetcode id=1980 questionId=2107 slug=find-unique-binary-string lang=cpp site=leetcode.com title="Find Unique Binary String"
class Solution {
    public:
    string findDifferentBinaryString(vector<string>& nums) {
    string res;
    for (int i = 0; i < nums.size(); i++)
    res += (nums[i][i] == '0' ? '1' : '0');
    return res;
    }
    };
