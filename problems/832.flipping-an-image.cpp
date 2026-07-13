// @leetcode id=832 questionId=861 slug=flipping-an-image lang=cpp site=leetcode.com title="Flipping an Image"
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int i = 0, j = row.size() - 1;
            while (i <= j) {
                if (i == j) {
                    row[i] ^= 1;
                } else {
                    int tmp = row[i] ^ 1;
                    row[i] = row[j] ^ 1;
                    row[j] = tmp;
                }
                i++;
                j--;
            }
        }
        return image;
    }
};
