class Solution {
public:
    int characterReplacement(string s, int k) {
        // maintain hashtable for most freq char in a wnd
        // reduce wnd when repl exceeds k
        // repl = len(wnd) - freq of most freq chr
        
        // unordered_map<char, int> mp;
        vector<int> v(26,0);
        string w;
        int i=0, res=0, mfq=0;

        while(i < s.size()){
            int repl=0;
            w += s[i];
            v[s[i]-'A']++;
            mfq = *max_element(v.begin(), v.end());
            repl = (int)w.size() - mfq;
            while(repl > k){
                v[w[0]-'A']--;
                w.erase(0,1);
                mfq = *max_element(v.begin(), v.end());
                repl = (int)w.size() - mfq;
            }
            res = max(res, (int)w.size());
            i++;
        }
        return res;
    }
};
