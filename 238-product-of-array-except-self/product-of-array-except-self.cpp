class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> op;
        
        if(n<1){
            return op;
        }
            
        
        int res = 1;
        for(int i=0;i<n;++i)
        {
            res *= nums[i];
            op.push_back(res);            
        }
        
       
        res = 1;
        for(int i=n-1;i>0;--i)
        {
            op[i] = op[i-1]*res;
            res *= nums[i];
        }
        op[0] = res;
        
        return op;
    }
};