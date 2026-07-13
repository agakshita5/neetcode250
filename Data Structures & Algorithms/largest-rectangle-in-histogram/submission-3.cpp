class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        // monotonic stack: stores nearst smaller elem from left and right
        // [left], [right] vector, [left_st], [right_st] stacks
        int n= h.size();
        int maxArea=INT_MIN;

        vector<int> left(n,-1), right(n,n);
        stack<int> left_st, right_st;
        left_st.push(0);
        right_st.push(n-1);

        // nearest elem from L-R
        for(int i=1;i<n;i++){
            while(!left_st.empty() && h[i] <= h[left_st.top()]){
                left_st.pop();
            }
            if(!left_st.empty()) left[i] = left_st.top(); // st.top() is nearest smaller from left for curr idx elem
            left_st.push(i);
        }

        // nearest elem from R-L
        for(int i=n-2;i>=0;i--){
            while(!right_st.empty() && h[i] <= h[right_st.top()]){
                right_st.pop();
            }
            if(!right_st.empty()) right[i] = right_st.top(); // st.top() is nearest smaller from right for curr idx elem
            right_st.push(i);
        }
        
        for(int i=0;i<n;i++){
            int area = h[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
