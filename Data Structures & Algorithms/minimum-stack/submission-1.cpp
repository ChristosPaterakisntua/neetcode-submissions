class MinStack {
public:
    stack<int> stk;
    stack<int> mins;
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        mins.push(min(val, mins.empty() ? val : mins.top()));
    }
    
    void pop() {
        stk.pop();
        mins.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
