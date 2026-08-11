class Solution {
public:
    int search(vector<int>& arr, int target) {
        // 1 binary search to find target after getting pivot in particular segment
        int n = arr.size();

        int l=0, r=n-1;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(target == arr[mid]) return mid;

            if(arr[mid] < arr[r]){
                // m < t <= r
                if(arr[mid] < target && target <= arr[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }else{ // [l] < [mid]
                // l <= t < m
                if(arr[l] <= target && target < arr[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};
