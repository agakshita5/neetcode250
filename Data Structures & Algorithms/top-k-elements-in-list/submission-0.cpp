class Solution {
public:
// example: arr-> 1, 2, 2, 7, 3, 3
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); // 6
        map<int, int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++; // freq hashmap
        // 1,1  2,2  7,1  3,2

        vector<vector<int>> bkts(n+1); // bkts arr of n+1 size as any elem can appear n times
        vector<int> ans;

        for(auto p: mp){
            // store nums elem in bkts corresponding to their freq
            bkts[p.second].push_back(p.first);
            // 0-   1-1,7  2-2,3  3-  4-  5- 6-
        }
        
        for(int i = n; i >= 0 && k > 0; i--){
            for(int num : bkts[i]){
                ans.push_back(num);
                k--;

                if(k == 0) break;
            }
        }
        return ans;
    }
};
