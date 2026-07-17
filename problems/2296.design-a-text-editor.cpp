// @leetcode id=2296 questionId=2389 slug=design-a-text-editor lang=cpp site=leetcode.com title="Design a Text Editor"
class TextEditor {
    vector<char> left, right; // left: reversed order not needed; left.back() is char just before cursor

public:
    TextEditor() {
    }

    void addText(string text) {
        for (char c : text) left.push_back(c);
    }

    int deleteText(int k) {
        int cnt = 0;
        while (k-- > 0 && !left.empty()) {
            left.pop_back();
            cnt++;
        }
        return cnt;
    }

    string cursorLeft(int k) {
        while (k-- > 0 && !left.empty()) {
            right.push_back(left.back());
            left.pop_back();
        }
        int len = min((int)left.size(), 10);
        string result(left.end() - len, left.end());
        return result;
    }

    string cursorRight(int k) {
        while (k-- > 0 && !right.empty()) {
            left.push_back(right.back());
            right.pop_back();
        }
        int len = min((int)left.size(), 10);
        string result(left.end() - len, left.end());
        return result;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
