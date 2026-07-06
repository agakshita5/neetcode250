class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        // i+k+j=0 -> i = -(j+k) -> -i = j+k
        // i -> -i as target for 2sum(k, j)
        int n=arr.size();
        vector<vector<int>> set;
        // -1 0 1 2 -1 -4
        sort(arr.begin(), arr.end());
        int i=0;
        // -4 -1 -1 0 1 2
        while(i<n){
            int k=i+1, j=n-1;
            while(k<j){
                if(arr[k]+arr[j] < -(arr[i])){
                    k++;
                }
                else if(arr[k]+arr[j] > -arr[i]){
                    j--;
                }else{
                    vector<int> v = {arr[i], arr[k], arr[j]};
                    if(find(set.begin(), set.end(), v) == set.end()){
                        set.push_back(v);
                    }
                    j--;
                }
            }
            i++;
        }
        return set;
    }
};
