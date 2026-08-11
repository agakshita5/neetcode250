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

        int l=0, r=n-1;
        while(l < r){
            if(arr[l] <= arr[r]){
                return arr[l];
            }

            int mid = l + (r-l)/2;
            
            if(arr[mid] <= arr[r]){
                // right sorted -> search l...mid
                r = mid;
            }
            else{
                // left sorted -> discard left and go right
                l = mid+1;
            }
        }
        return arr[l];
    }
};
