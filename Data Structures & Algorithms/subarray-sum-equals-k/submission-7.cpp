class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        // make a hash table 'pfs' i:0-n; comapre each val of pfs to k - yes cnt++, else nothing
        // from i=1 to n -> traverse 
        // arr[i] & h[i+1]-h[i-1] compare with k - yes cnt++, else nothing.

        int cnt=0;
        int n= arr.size(); 
        map<int, int> mp; // pfs, count_pfs
        mp[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            cnt+=mp[sum-k];
            mp[sum]++;
        }
    return cnt;
    }
};
        // for(int i=0;i<n;i++){ 
        //     if(k==0){
        //         if(pfs[i]-k==0) cnt++;
        //     }else{
        //         if(find(pfs.begin(), pfs.end(), pfs[i+1]-k) != pfs.end() || pfs[i]-k==0) cnt++;
        //     }
