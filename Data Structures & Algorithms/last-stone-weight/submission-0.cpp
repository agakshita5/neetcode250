class Solution {
public:
    priority_queue<int> pq;

    int lastStoneWeight(vector<int>& stones) {
        for(int n: stones){
            pq.push(n);
        }

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x < y) pq.push(y-x);
            else if(x > y) pq.push(x-y);
        }

        if(pq.empty()) return 0;

        return pq.top();
    }
};
