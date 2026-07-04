class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum: subarr sum
        // hash table: {0, 1} for k==0 cases
        // pfs, pfs_count
        // say n=4 -> mp(n+1)
        // [2 -1 1 2]
        // mp: 0,1 -> traverse arr and keep updating mp
        // if pfs_arr-k exists in mp then cnt+=mp[pfs_arr-k] -> mp[pfs_arr-k]++;
        // if pfs_arr-k not exists in mp then mp[pfs_arr]++;

        // mp[0]=1
        // pfs = 2  ; 2-2 = 0   ;   cnt=0+1 ;   mp[0]=2 
        // pfs = 1  ; 1-2 = -1  ;   mp[1]=1
        // pfs = 2  ; 2-2 = 0   ;   cnt=1+2 ;   mp[0]=3 
        // pfs = 4  ; 4-2 = 2   ;   cnt=3+1 ;   mp[2]=2 & mp[4]=1


        int cnt=0, pfs=0;
        map<int, int> mp;
        mp[0]=1;
        for(int n: nums){
            pfs+=n;
            // if(mp.find(pfs-k) != mp.end()){
                cnt = cnt + mp[pfs-k];
                // mp[pfs-k]++;
            // }else{
                mp[pfs]++;
            // }
        }
        return cnt;

    }
};