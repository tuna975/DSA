class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& its) : k(k) {

        for (auto it : its) {

            if (pq.size() < k) {
                
                pq.push(it);
            } 
            else if (it > pq.top()) {

                pq.pop();
                pq.push(it);
            }
        }
        
    }
    
    int add(int val) {

        if (pq.size() < k) {

            pq.push(val);

        } 
        else if (val > pq.top()) {

            pq.pop();
            pq.push(val);
        }

        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, its);
 * int param_1 = obj->add(val);
 */