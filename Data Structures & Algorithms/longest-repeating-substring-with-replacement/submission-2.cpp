class Solution {
public:
    int characterReplacement(string s, int k) {
        // maintain vector for most freq char in a wnd
        // reduce wnd when repl exceeds k
        // repl = len(wnd) - freq of most freq chr
        
        vector<int> v(26,0);
        int l=0, r=0, res=0, mfq=0;

        while(r < s.size()){
        
            int repl=0;
            int val = s[r]-'A';
            v[val]++;
            mfq = max(mfq, v[val]);
            while((r-l+1) - mfq > k){
                v[s[l]-'A']--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
