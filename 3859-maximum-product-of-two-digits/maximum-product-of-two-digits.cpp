class Solution {
public:

    

    int maxProduct(int n) {
        priority_queue<int> pq;

        while(n > 0)
        {
            int num = n%10;
            n = n/10;
            pq.push(num);
        }


        int first = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();


        return first*sec;
        
    }
};