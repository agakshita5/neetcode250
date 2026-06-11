class Solution {
public:
    bool isanagram(string a, string b){
        if(a.size()!=b.size()) return false;
        unordered_map<char,int> fq1;
        for(char i:a){
            fq1[i]++;
        }
        unordered_map<char,int> fq2;
        for(char i:b){
            fq2[i]++;
        }
        
        return fq1==fq2;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(strs[i]) == mp.end()){
                vector<string> v;
                mp.insert({strs[i],1});
                v.push_back(strs[i]);
                for(int j=i+1;j<n;j++){
                    if(isanagram(strs[i],strs[j])){
                        mp.insert({strs[j],1});
                        v.push_back(strs[j]);
                    }
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};
