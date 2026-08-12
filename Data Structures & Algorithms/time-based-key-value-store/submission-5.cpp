class TimeMap {
public:
    map<string, vector<pair<string,int>>> mp;

    TimeMap() {}
    
    void set(string key, string value, int ts) {
        mp[key].push_back({value, ts});
    }
    
    string get(string key, int ts) {
        if(mp.find(key) != mp.end()){
            const vector<pair<string,int>>& v = mp[key];

            int l = 0, h = v.size()-1, idx=-1;
            string ansStr;
            while(l<=h){
                int mid = l + (h-l)/2;
                if(v[mid].second <= ts){
                    idx = mid;
                    l = mid+1;
                }
                else h = mid-1;
            }
            if(idx >= 0) return v[idx].first;
        }
        return "";
    }
};
