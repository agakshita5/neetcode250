class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        // 2 pointers: l at start, r at end
        // l+r > t : r--    l+r < t : l++
        int n= arr.size();
        int l=0, r=n-1;
        while(l<r && arr[l]!=arr[r]){
            if(arr[l] + arr[r] > target) r--;
            else if (arr[l] + arr[r] < target) l++;
            else return {l+1, r+1};
        }
        return {l+1, r+1};
    }
};
