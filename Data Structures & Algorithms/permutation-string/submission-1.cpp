class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // same freq == permuations 
        vector<int> v(26,0);
        for(char i:s1) v[i-'a']++;

        int n = s1.size(), l=0;
        while(n <= s2.size() && l <= s2.size()-n){
            vector<int> fq(26);
            string w = s2.substr(l, n);
            for(char i:w) fq[i-'a']++;

            if(v == fq) return true; // found
            l++;
        }
        return false;
    }
};
