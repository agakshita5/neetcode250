class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        // binary search on rows
        // binary search on selected row
        // one-binary solution => 1D -> 2D

        int m = v.size(), n = v[0].size();
        int l=0, h=(m*n)-1;

        while(l<=h){
            int mid = l+(h-l)/2;
            int val = v[mid/n][mid%n];
            if(val > t) h=mid-1;
            else if(val < t) l=mid+1;
            else return true;
        }
        return false;
    }
};