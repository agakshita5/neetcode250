class Solution {
public:
    int totalHours(int k, vector<int>& p){
        int sum=0;
        for(int j=0;j<p.size();j++){
            sum += ceil((double)p[j] / k); 
            // OR ceil fn can be replaced with formula
            // a + b - 1 / b :: (p[j] + k - 1)/k
            // it is same as 
            // if(p[j] % k == 0) hrs = p[j] / k;
            // else hrs = (p[j] / k) + 1;
        }
        
        return sum;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int n= p.size();

        // answer space range
        int l=1, r = *max_element(p.begin(), p.end());
        int k, ans = r;
        while(l <= r){
            k = l + (r-l)/2;
            int hrs = totalHours(k, p);
            // false case
            if(hrs > h){
                l = k + 1;
            }else{ // true case
                ans = k;
                r = k - 1;
            }
        }
        return ans;

    }
};