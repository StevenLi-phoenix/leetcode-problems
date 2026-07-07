// @leetcode id=1476 questionId=1572 slug=subrectangle-queries lang=cpp site=leetcode.com title="Subrectangle Queries"
class SubrectangleQueries {
private:
    vector<vector<int>> grid;
    vector<array<int, 5>> updates; // row1, col1, row2, col2, value

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : grid(rectangle) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        for (int i = updates.size() - 1; i >= 0; --i) {
            auto& u = updates[i];
            if (u[0] <= row && row <= u[2] && u[1] <= col && col <= u[3]) {
                return u[4];
            }
        }
        return grid[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
