class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n : arr){
            if(pq.size() < k) pq.push(n);
            else{
                if(n > pq.top()){
                    pq.push(n);
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
