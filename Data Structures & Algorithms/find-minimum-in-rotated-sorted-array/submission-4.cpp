class Solution {
public:
    int findMin(vector<int> &arr) {
        // minimum would be at the cut
        // look for cut/rotation point/pivot
        // in binary search -> one half guranteed to be sorted
        // and sorted half CANNOT have cut
        // right half sorted :: keep mid, go left
        // left half sorted :: discard left, go right

        int n = arr.size();
        // if(n==1) return arr[0];

        int l=0, r=n-1, ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(l == r){
                return arr[mid];
            }
            
            if(arr[mid] <= arr[r]){
                // right sorted -> search l...mid
                ans = arr[mid];
                r = mid;
            }
            else if(arr[l] <= arr[mid]){
                // left sorted -> discard left and go right
                l = mid+1;
            }
        }
        return ans;
    }
};
