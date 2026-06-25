// @leetcode id=744 questionId=745 slug=find-smallest-letter-greater-than-target lang=cpp site=leetcode.com title="Find Smallest Letter Greater Than Target"
class Solution {
    public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    auto it = upper_bound(letters.begin(), letters.end(), target);
    if (it == letters.end()) return letters[0];
    return *it;
    }
    };
