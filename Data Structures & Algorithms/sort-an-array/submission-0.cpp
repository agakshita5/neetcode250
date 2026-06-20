class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r){
        int n1= mid-l+1;
        int n2 = r-mid;

        vector<int> L(n1), R(n2);
        for(int i=0;i<n1;i++){
            L[i] = nums[l+i];
        }
        for(int j=0;j<n2;j++){
            R[j] = nums[mid+1+j];
        }
        int i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                nums[k] = L[i];
                i++;
            }else{
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k] = L[i];
            k++;
            i++;
        }
        while(j<n2){
            nums[k] = R[j];
            j++;
            k++;
        }
    }
    void mergesort(vector<int>& nums, int l, int r){
        if(l<r){
            int mid = l + (r-l)/2;
            mergesort(nums, l, mid);
            mergesort(nums, mid+1, r);
            merge(nums, l, mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int l = 0, r = n-1;
        mergesort(nums, l, r);
        return nums;
    }
};