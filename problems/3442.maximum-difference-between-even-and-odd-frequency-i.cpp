// @leetcode id=3442 questionId=3753 slug=maximum-difference-between-even-and-odd-frequency-i lang=cpp site=leetcode.com title="Maximum Difference Between Even and Odd Frequency I"
class Solution {
    public:
    int maxDifference(string s) {
    unordered_map<char,int> freq;
    for(char c : s) freq[c]++;
    int maxOdd = INT_MIN, minEven = INT_MAX;
    for(auto& p : freq) {
    if(p.second % 2 == 1) maxOdd = max(maxOdd, p.second);
    else minEven = min(minEven, p.second);
    }
    return maxOdd - minEven;
    }
    };
