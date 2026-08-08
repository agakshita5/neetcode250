class Solution {
public:
    string minWindow(string s, string t) {
        // hashtable consists of t's char freq
        // sliding wnd until freq of t matched
        // then shrink until valid and find res if len(res) < prev len
        // update res and len

        map<char, int> mp;
        int n1 = s.size(), n2 = t.size();
        
        if(n2 > n1) return "";
        
        for(int i=0;i<n2;i++) mp[t[i]]++; // mp stores freq of t's chr

        int bestSt=-1, bestLen=INT_MAX;
        int len = 0; 
        int l=0, r=0;
        int reqChr = n2; // this much chr required
        // iterating in s
        while(l <= r && r<n1){
            if(mp.find(s[r]) != mp.end()){
                mp[s[r]]--;
                if(mp[s[r]] >= 0) reqChr--;
            }
            // len = res.size();
            while(reqChr == 0){
                len = r - l + 1; // 5
                if(len < bestLen){
                    bestSt = l;
                    bestLen = len;
                }

                char toRemove = s[l];
                if(mp.find(toRemove) != mp.end()){
                    mp[toRemove]++;
                    if(mp[toRemove] > 0) reqChr++;
                }
                l++;
            }
            r++;
        }
        if(bestSt == -1) return "";
        
        return s.substr(bestSt, bestLen);
    }
};
