class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

    KthLargest(int k, vector<int>& nums) {
        this->K = k;

        for(int n: nums){
            if(pq.size() < k){
                pq.push(n);
            }else{ // sz >= k
                if(n > pq.top()){
                    pq.push(n);
                    pq.pop(); // as sz becomes > k when 'n' pushed
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < K){
            pq.push(val);
        }else{ // sz >= K
            if(val > pq.top()){
                pq.push(val);
                pq.pop(); // as sz becomes > k when 'val' pushed
            }
        }

        return pq.top();
    }
};
