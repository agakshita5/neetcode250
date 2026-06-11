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
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            vector<int> fq(26);
            // if(mp.find(strs[i]) == mp.end()){
                for(char ch: strs[i]){
                    fq[ch-'a']++;
                }

                string key = "";
                for(int j: fq){
                    key += "#";
                    key += to_string(j);
                }

                mp[key].push_back(strs[i]);
            // }
        }
        for(auto &p: mp) ans.push_back(p.second);

        return ans;
    }
};
