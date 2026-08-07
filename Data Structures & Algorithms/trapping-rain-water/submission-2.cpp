class Solution {
public:
    int trap(vector<int>& h) {
        /*
        //  maxleft maxright 
        int n= h.size();

        // L-R
        vector<int> ml(n);
        ml[0] = h[0];
        for(int i=1;i<n;i++){
            ml[i] = max(ml[i-1], h[i]);
        }
        // R-L
        vector<int> mr(n);
        mr[n-1] = h[n-1];
        for(int i=n-2;i>=0;i--){
            mr[i] = max(mr[i+1], h[i]);
        }

        // find sum of water trapped
        int res=0;
        for(int i=0;i<n;i++){
            res+= min(ml[i], mr[i]) - h[i];
        }
        return res;
        */
        
        // monotonic approach
        int n = h.size();
        stack<int> st;
        int res=0;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && h[i] > h[st.top()]){
                int idx = st.top();
                st.pop();
                int area;
                if(!st.empty()){
                    int wd = i - st.top() - 1;
                    area = wd * (min(h[st.top()], h[i]) - h[idx]);
                }
                else area = 0;

                res += area;
            }
            st.push(i);
        }
        return res;
    }
};
