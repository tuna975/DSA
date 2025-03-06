class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int s = n*n;

        vector<int> a(s+1, 0);


        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                int el = grid[i][j];
                a[el]++;
            }
        }

        int two;
        int no;

        for(int i = 0; i<s+1; i++)
        {
            if(a[i] == 2)
            {
                two = i;
            }

            if(a[i] == 0)
            {
                no = i;
            }
        }

        return {two, no};
    }
};