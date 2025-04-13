class Solution {
    #define ll long long
    int MOD = 1000000007;

    ll solve(ll a,ll b){
        ll res = 1;
        while(b){
            if(b&1)
                res = (res * a) % MOD;
            a = (a*a) % MOD;
            b /= 2;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        return (solve(4,n/2) * solve(5,n-n/2))%MOD;
    }
};