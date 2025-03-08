class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0,j =0 ;
        int changes = 0 , ans = INT_MAX;
        for(int temp = 0;temp<k;temp++){
            if(blocks[j++] == 'W') changes++;
        }
        ans = min(ans,changes);
        while(j<blocks.size()){
            
            if(blocks[j] == 'W')changes++;
            if(blocks[i]  == 'W') changes--;

            ans = min(ans,changes);
            j++;
            i++;
        }
        return ans;
    }
};