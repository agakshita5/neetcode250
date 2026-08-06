class Solution{
    public:
        int maxArea(vector<int>& h){
            int n = h.size();
            int i=0, j=n-1, res=0;
            while(i<j){
                int area = (j-i) * min(h[i], h[j]);
                res = max(res, area);

                if(h[i] < h[j]) i++;
                else j--;
            }
            return res;

        }
};