class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();  

        sort(arr.begin(), arr.end()); 

        vector<vector<int>> res; 

        int mini = INT_MAX;  
        int diff = 0; 

       
        for(int i = 1; i < n; i++) {
            diff = arr[i] - arr[i - 1];  
            mini = min(mini, diff);  
        }

       
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] == mini) {  
                res.push_back({arr[i - 1], arr[i]}); 
            }
        }

        return res;  
    }
};