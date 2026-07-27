class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding wnd
        // maintian hash - table for curr freq of chrs within that wnd
        // maintain max len for each iteration

        unordered_map<char, int> mp;
        string w;
        int res = 0;
        for(int i=0;i<s.size();i++){
            // if(w.empty()){w += s[i];

            while(mp[s[i]] == 1){
                mp[w[0]] = 0;
                w.erase(0, 1);
            }

            if(mp[s[i]] == 0){
                mp[s[i]] = 1;
                w += s[i];
            }
            
            res = max(res, (int)w.size());
        }
        return res;
    }
};
