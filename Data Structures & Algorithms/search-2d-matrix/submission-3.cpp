class Solution {
public:
    int binSearchRow(vector<vector<int>>& v, int t){
        int m = v.size(), n = v[0].size();
        int l=0, h=(m*n)-1;

        while(l<=h){
            int mid = l+(h-l)/2;
            if(v[mid/n][mid%n] > t) h=mid-1;
            else if(v[mid/n][mid%n] < t) l=mid+1;
            else return mid;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search on rows
        // binary search on selected row
        int rowIdx = binSearchRow(matrix, target);
        if(rowIdx != -1) return true;
        return false;
    }
};


// int n = nums.size();
// int l=0, h=n-1;

// while(l<=h){
//     int mid = l+(h-l)/2;
//     if(nums[mid] > target) h=mid-1;
//     else if(nums[mid] < target) l=mid+1;
//     else return mid;
// }
// return -1;