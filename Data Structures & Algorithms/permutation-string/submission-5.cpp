class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // same freq == permuations 
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;

        vector<int> v(26,0);
        for(char i:s1) v[i-'a']++;

        vector<int> fq(26);
        for(char i: s2.substr(0, n1)) fq[i-'a']++; 
        if(v == fq) return true;

        int l = n1;
        while(l < n2){
            char toRemove = s2[l-n1], toAdd = s2[l];
            fq[toRemove - 'a']--;
            fq[toAdd - 'a']++;

            if(v == fq) return true; // found
            l++;
        }
        return false;
    }
};
