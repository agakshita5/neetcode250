class MinStack {
public:
    vector<int> arr;

    MinStack() {
        vector<int> arr;
    }
    void push(int val) {
        arr.push_back(val);
    }
    
    void pop() {
        if(!arr.empty()) arr.pop_back();
    }
    
    int top() {
        if(!arr.empty()) return arr[arr.size()-1];
    }
    
    int getMin() {
        if(!arr.empty()) return *min_element(arr.begin(), arr.end());
    }
};
