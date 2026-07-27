class Solution {
public:
    int maxProfit(vector<int>& p) {
        // in arr store 'smallest' elem's idx to the left for any elem
        // reiterate to calc profit and maintain max
        // return that max
        int n = p.size();
        vector<int> v(n,-1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && p[i] < p[st.top()]) st.pop();
            
            if(!st.empty()) v[i] = st.top();

            if(st.empty()) st.push(i);
        }
        int pf = 0;
        for(int i=0;i<n;i++){
            if(v[i] == -1) continue;
            pf = max(pf, p[i] - p[v[i]]);
        }
        return pf;
    }
};
