class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        struct Compare {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return a[0] > b[0];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq; 

        vector<vector<int>> ans;

        for(auto p: points){
            int dist = p[0]*p[0] + p[1]*p[1];
            pq.push({dist, p[0], p[1]});
        }

        while(k--){
            vector<int> pt = pq.top();
            ans.push_back({pt[1], pt[2]});
            pq.pop();
        }

        return ans;
    }
};
