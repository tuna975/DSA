class Solution {
public:
    bool check(vector<pair<int,int>>& a)
    {
        int cnt = 1;
        int last = a[0].second;

        for(int i =1; i<a.size(); i++)
        {
            if(a[i].first >= last)
            {
                cnt++;
                last = a[i].second;

                if(cnt == 3)
                {
                    return true;
                }
            }
            else{
                last = max(last, a[i].second);
            }
        }

        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> xs;
        vector<pair<int,int>> ys;

        for(auto it : rectangles)
        {
            xs.push_back({it[0], it[2]});
            ys.push_back({it[1], it[3]});


        }

        bool flag = false;
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());


        if(check(xs))
        {
            flag = true;
        }
        if(check(ys))
        {
            flag = true;
        }

        return flag;
    }
};