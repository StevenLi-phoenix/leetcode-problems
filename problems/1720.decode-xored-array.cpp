// @leetcode id=1720 questionId=1839 slug=decode-xored-array lang=cpp site=leetcode.com title="Decode XORed Array"
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr;
        arr.push_back(first);

        for (int code : encoded) {
            arr.push_back(arr.back() ^ code);
        }

        return arr;
    }
};
