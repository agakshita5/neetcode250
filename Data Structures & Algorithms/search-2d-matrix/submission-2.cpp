class Solution {
public:
    int binSearch(vector<int>& v, int t){
        int n = v.size();
        int l=0, h=n-1;

        while(l<=h){
            int mid = l+(h-l)/2;
            if(v[mid] > t) h=mid-1;
            else if(v[mid] < t) l=mid+1;
            else return mid;
        }
        return -1;
    }
    int binSearchRow(vector<vector<int>>& v, int t){
        int m = v.size(), n = v[0].size();
        int l=0, h=m-1;

        while(l<=h){
            int mid = l+(h-l)/2;
            if(v[mid][0] > t) h=mid-1;
            else if(v[mid][n-1] < t) l=mid+1;
            else return mid;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search on rows
        // binary search on selected row
        int rowIdx = binSearchRow(matrix, target);
        if(rowIdx != -1){
            int valIdx = binSearch(matrix[rowIdx], target);
            if(valIdx != -1) return true;
        }
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