class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<int> st;
        st.push(0);
        vector<int> v(n,0);
        int i=1;
        while(i<n ){ // 1 2 3 4 5 6(X)
            while(!st.empty() && t[i] > t[st.top()]){ // t1>t0,  t2>t1 X, t3>t2, t4>t3, t5>t4, t5>t3, t5>t1
                v[st.top()] = i - st.top(); // v[0]=1-0, v[2]=3-2, v[4]=5-4, v[3]=5-3, v[1]=5-1
                st.pop(); // 
            }
                st.push(i); // 5
                i++; // 2 3 4 5 6
        }

        return v;
    }
    // TC: O(n): as for every index it is either pushed or popped from stack
};
