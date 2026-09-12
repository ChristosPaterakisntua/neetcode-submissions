class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        if (!mins.empty()) mins.push(min(val, mins.top()));
        else mins.push(val);
    }
    
    void pop() {
        data.pop();
        mins.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int> data;
    stack<int> mins;
};
