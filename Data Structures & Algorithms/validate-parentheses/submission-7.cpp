class Solution {
public:
    bool isValid(string s) {
        stack<char> pars;
        if (s.length() % 2) return false;
        for (char c : s) {
            if (isOpening(c)) {
                pars.push(c);
            }
            else if (pars.empty()) return false;
            else if (pars.top() == closing(c)) {
                pars.pop();
            }
            else return false;
        }
        return pars.empty();
    }
private:
    bool isOpening(char c) {
        if (c == '(' || c == '{' || c == '[') return true;
        return false;
    }

    char closing(char c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        if (c == '}') return '{';
        return ' ';
    }
};
