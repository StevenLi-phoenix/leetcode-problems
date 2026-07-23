// @leetcode id=2408 questionId=2555 slug=design-sql lang=cpp site=leetcode.com title="Design SQL"
class SQL {
public:
    unordered_map<string, int> colCount;
    unordered_map<string, int> nextId;
    unordered_map<string, map<int, vector<string>>> tables;

    SQL(vector<string>& names, vector<int>& columns) {
        for (int i = 0; i < (int)names.size(); i++) {
            colCount[names[i]] = columns[i];
            nextId[names[i]] = 1;
            tables[names[i]] = {};
        }
    }

    bool ins(string name, vector<string> row) {
        if (colCount.find(name) == colCount.end()) return false;
        if ((int)row.size() != colCount[name]) return false;
        int id = nextId[name]++;
        tables[name][id] = row;
        return true;
    }

    void rmv(string name, int rowId) {
        auto it = tables.find(name);
        if (it == tables.end()) return;
        it->second.erase(rowId);
    }

    string sel(string name, int rowId, int columnId) {
        auto it = tables.find(name);
        if (it == tables.end()) return "<null>";
        auto rowIt = it->second.find(rowId);
        if (rowIt == it->second.end()) return "<null>";
        if (columnId < 1 || columnId > (int)rowIt->second.size()) return "<null>";
        return rowIt->second[columnId - 1];
    }

    vector<string> exp(string name) {
        vector<string> res;
        auto it = tables.find(name);
        if (it == tables.end()) return res;
        for (auto& [id, row] : it->second) {
            string s = to_string(id);
            for (auto& cell : row) s += "," + cell;
            res.push_back(s);
        }
        return res;
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */
