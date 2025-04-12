class Solution {
    #define ll long long
    ll res = 0;
    unordered_set<ll> st;
    vector<ll> a;

    void comp(int& n){
        a[0] = 1;
        a[1] = 1;
        for(ll i=2;i<=10;++i)
            a[i] = i*a[i-1];
    }
    ll cntall(vector<ll>& freq,int n){
        ll count = a[n];
        for(int i=0;i<=9;++i)
            count /= a[freq[i]];
        return count;
    }

    ll allar(string num,int& n){
        sort(num.begin(),num.end());
        if(st.count(stoll(num)))
            return 0;
        
        st.insert(stoll(num));
      
        vector<ll> freq(10);
        for(char& c: num)
            freq[c-'0']++;
        
        ll tot = cntall(freq,n);
        ll perm = 0;
        if(freq[0]>0){
            freq[0]--;
            perm = cntall(freq,n-1);
        }
        return  tot - perm;
    }

    bool pal(string& num,int& n,int& k){
        return (stoll(num)%k==0);
    }
    void solve(int pos,int& n,string& num,int& k){
        if(pos>=(n+1)/2){
            if(pal(num,n,k))
                res += allar(num,n);
            return;
        }

        char start = pos==0? '1':'0';
        while(start<='9'){
            num[pos]=start;
            num[n-pos-1]=start;
            solve(pos+1,n,num,k);
            start++;
        }
        num[pos]=' ';
    }
public:
    long long countGoodIntegers(int n, int k) {
        a = vector<ll>(11);
        comp(n);
        string num(n,' ');
        solve(0,n,num,k);
        return res;
    }
};