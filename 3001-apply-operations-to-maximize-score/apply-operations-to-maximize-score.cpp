class Solution {
public:
#define ll long long
    ll mod = 1e9 + 7;
    unordered_map<ll, ll> mp;
    ll power(ll a, ll b) {
        ll x = 1;
        a %= mod;
        while (b) {
            if (b & 1)
                x = ((x % mod) * (a % mod)) % mod;
            a = ((a % mod) * (a % mod)) % mod;
            b >>= 1;
        }
        return x % mod;
    }
    ll compute(ll& a) {
        ll ans = 0;
        for (ll i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                ll cnt = 0;
                while (a % i == 0) {
                    cnt++;
                    a /= i;
                }
                mp[i] = cnt;
            }
        }
        if (a > 1)
            mp[a] = 1;
        ans = mp.size();
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>b;
        for(int i=0;i<n;i++){
            mp.clear();
            ll x=nums[i];
            b.push_back(compute(x));
        }

        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && b[i] > b[st.top()])
                st.pop();
            left[i] = (st.empty()) ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && b[i] >= b[st.top()])
                st.pop();
            right[i] = (st.empty()) ? (n - i) : (st.top() - i);
            st.push(i);
        }

        vector<pair<ll, ll>> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back({nums[i], (ll)left[i] * right[i]});
        }
        sort(ans.rbegin(), ans.rend());

        ll fin = 1;
        for (int i = 0; i < n; i++) {
            ll op = min((ll)k, ans[i].second);
            fin = (fin * power(ans[i].first, op)) % mod;
            k -= op;
            if (k == 0)
                break;
        }

        return fin;
    }
};