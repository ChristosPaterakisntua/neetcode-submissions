class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (const char &c : s) {
            if (isOpening(c)) myStack.push(c);
            else if (myStack.empty()) return false;
            else {
                if (correspondingParentheses(c) == myStack.top()) myStack.pop();
                else return false;
            }
        }
        return myStack.empty();
    }
private:
    bool isOpening(const char &c) {
        if (c == '(' || c == '[' || c == '{') return true;
        if (c == ')' || c == ']' || c == '}') return false;
        throw logic_error("Not a parethese");
    }

    char correspondingParentheses(const char &c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        if (c == '}') return '{';
        throw logic_error("Not a parethese");
    }
};
