class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        stack<int> minSt;
        stack<int> st;
    }
    void push(int val) {
        st.push(val);
        if (minSt.empty()) minSt.push(val);
        else minSt.push(min(val, minSt.top()));
    }
    
    void pop() {
        minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
