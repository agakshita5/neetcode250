class Solution {
public:
    int binarySearch(vector<int>& v, int l, int r, int t){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid] > t) r = mid-1;
            else if(v[mid] < t) l = mid+1;
            else return mid;
        }
        return -1;
    }

    int search(vector<int>& arr, int target) {
        // 2 binary search
        // 1. to find pivot idx
        // 2. to find target after getting pivot in particular segment
        int n = arr.size();

        int l=0, r=n-1, pv;
        while(l<r){
            if(l==r) pv = l;
            int mid = l + (r-l)/2;

            if(arr[mid] < arr[r]) r = mid;
            else l = mid + 1;
        }
        pv = l;
 
        if(target <= arr[n-1]){ // right side
            return binarySearch(arr, pv, n-1, target);
        }else{ // left side
            return binarySearch(arr, 0, pv-1, target);
        }
    }
};
