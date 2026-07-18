class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()){
            minStk.push(val);
        }
        else{
            minStk.push(min(val, minStk.top()));
        }
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
