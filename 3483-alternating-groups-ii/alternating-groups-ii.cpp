class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) {
    int n = arr.size(), i = 0,j = 0, res = 0;
    while(i < n){
        if(j - i + 1 < k){
            if(j - i == 0 or arr[j%n]!=arr[(j-1)%n]){
                j++;
            }
            else{
                i = j;
            }
        }
        else{
            if(arr[j%n]!=arr[(j-1)%n]){
                i++;
                j++;
                res++;
            }
            else{
                i = j;
            }
        }
    }
    return res;
}
};