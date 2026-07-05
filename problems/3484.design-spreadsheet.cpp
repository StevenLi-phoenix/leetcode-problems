// @leetcode id=3484 questionId=3797 slug=design-spreadsheet lang=cpp site=leetcode.com title="Design Spreadsheet"
class Spreadsheet {
public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        cells[cell] = value;
    }

    void resetCell(string cell) {
        cells.erase(cell);
    }

    int getValue(string formula) {
        int plusPos = formula.find('+', 1);
        string x = formula.substr(1, plusPos - 1);
        string y = formula.substr(plusPos + 1);
        return resolve(x) + resolve(y);
    }

private:
    unordered_map<string, int> cells;

    int resolve(const string& token) {
        if (isdigit(token[0])) return stoi(token);
        auto it = cells.find(token);
        return it != cells.end() ? it->second : 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
