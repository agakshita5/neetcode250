class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

    KthLargest(int k, vector<int>& nums) {
        this->K = k;

        if(nums.empty()) return;

        for(int n: nums){
            if(pq.size() == k){
                if(n >= pq.top()){
                    pq.push(n);
                    pq.pop(); // as sz becomes > k when 'n' pushed
                    continue;
                }else{
                    continue;
                }
            }
            pq.push(n);
        }
    }
    
    int add(int val) {
        if(pq.size() == K){
            if(val >= pq.top()){
                pq.push(val);
                pq.pop(); // as sz becomes > k when 'val' pushed
                return pq.top();
            }else{
                return pq.top();
            }
        }

        pq.push(val);

        return pq.top();
    }
};
