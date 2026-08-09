class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        /*
        // first max in first wnd
        // sliding wnd and gwt max at each wnd
        // O(n*k) time as 'k' size window all over arr
        // and iterating though each elem within that wnd
        int n = arr.size();
        int i = 0;
        vector<int> v;
        while(i <= n-k){
            int maxElem = arr[i];
            for(int j=i+1;j<i+k;j++){
                maxElem = max(maxElem, arr[j]);
            }
            v.push_back(maxElem);
            i++;
        }
        return v;
        */

        // data struct - tells curr max elem of the wnd in O(1) time ––> heap
        
        // dequeue implementation
        deque<int> dq;
        int n= arr.size();
        vector<int> v;

        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[dq.back()] < arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        v.push_back(arr[dq.front()]);

        int i = k;
        while(i < n){
            // while max elem (front()) is out of wnd – pop it
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front(); 
            // simply check curr elem > back – pop from back
            while(!dq.empty() && arr[dq.back()] < arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            v.push_back(arr[dq.front()]); // 1(2) 
            i++;
        }
        return v;
    }
};
