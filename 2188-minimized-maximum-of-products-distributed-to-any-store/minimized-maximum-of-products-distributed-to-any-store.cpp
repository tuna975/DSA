
class Solution {  
public:  
    int minimizedMaximum(int n, vector<int>& quantities) {  
        int l = 1;  
        
        int r = *max_element(quantities.begin(), quantities.end());  
        
        while (l <= r) {  
            int mid = l + (r - l) / 2;  
          
            int cnt = 0;  
            for (int element : quantities) {  
                cnt += (element + mid -1) / mid;  
            }  
            
            if (cnt <= n) {  
              
                r = mid - 1;  
            } else {  
           
                l = mid + 1;  
            }  
        }  
        
   
        return l;  
    }  
};