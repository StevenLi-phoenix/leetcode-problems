// @leetcode id=1656 questionId=1775 slug=design-an-ordered-stream lang=cpp site=leetcode.com title="Design an Ordered Stream"
class OrderedStream {
public:
    vector<string> data;
    int ptr;

    OrderedStream(int n) {
        data.assign(n + 1, "");
        ptr = 1;
    }

    vector<string> insert(int idKey, string value) {
        data[idKey] = value;
        vector<string> chunk;
        while (ptr < (int)data.size() && !data[ptr].empty()) {
            chunk.push_back(data[ptr]);
            ptr++;
        }
        return chunk;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
