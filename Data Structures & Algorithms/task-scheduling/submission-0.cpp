class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq; // max heap to maintain most freq task
        deque<pair<int,int>> dq; // to maintain processed task, their next available time to get processed
        // [cnt, idleTime]

        vector<int> v(26,0);
        for(char c: tasks) v[c - 'A']++;

        for(int freq : v) if(freq > 0) pq.push(freq);

        int time = 0;

        while(!pq.empty() || !dq.empty()){
            time++;
            
            if(!pq.empty()){
                int cnt = pq.top() - 1;
                if(cnt > 0) dq.push_back({cnt, time + n});
                pq.pop();
            }else{
                time = dq.front().second;
            }

            if(!dq.empty() && dq.front().second == time){
                pq.push(dq.front().first);
                dq.pop_front();
            }
        }
        return time;
    }
};
