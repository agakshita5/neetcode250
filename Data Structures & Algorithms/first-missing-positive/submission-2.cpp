class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // traverse whole list
        // find smallest and i-smallest -> not found in list -> return
        int n=nums.size();
        // 1 2 4 5 6 3 1
        int i=0;
        while(i<n){
            if(nums[i]>0 && nums[i]<=n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};