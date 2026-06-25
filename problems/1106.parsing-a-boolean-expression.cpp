// @leetcode id=1106 questionId=1197 slug=parsing-a-boolean-expression lang=cpp site=leetcode.com title="Parsing A Boolean Expression"
class Solution {
public:
    int pos;
    
    bool parse(const string& expr) {
        char c = expr[pos];
        if (c == 't') { pos++; return true; }
        if (c == 'f') { pos++; return false; }
        
        if (c == '!') {
            pos += 2; // skip '!('
            bool result = !parse(expr);
            pos++; // skip ')'
            return result;
        }
        
        if (c == '&') {
            pos += 2; // skip '&('
            bool result = true;
            while (expr[pos] != ')') {
                if (expr[pos] == ',') pos++;
                result &= parse(expr);
            }
            pos++; // skip ')'
            return result;
        }
        
        if (c == '|') {
            pos += 2; // skip '|('
            bool result = false;
            while (expr[pos] != ')') {
                if (expr[pos] == ',') pos++;
                result |= parse(expr);
            }
            pos++; // skip ')'
            return result;
        }
        
        return false; // should never reach here
    }
    
    bool parseBoolExpr(string expression) {
        pos = 0;
        return parse(expression);
    }
};
