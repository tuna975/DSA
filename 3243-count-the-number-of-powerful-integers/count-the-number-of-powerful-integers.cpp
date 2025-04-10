class Solution {
    #define ll long long
    #define MAXI 17
    ll dp[MAXI][2];

   
    static bool check(const string& num, ll dig, const string& suffix, int limit) {
        if (dig < suffix.size()) return false;

        string suffs = num.substr(dig - suffix.size());
        bool sub = stoll(suffs) < stoll(suffix);

        if(sub){
            for (int i = 0; i < dig - suffix.size(); ++i) {
                if ((num[i] - '0') > limit) {
                    sub = false;
                    break;
                }
            }
        }
        return sub;
    }

   
    ll valid(const string& nums, ll idx, ll maxd,
                         bool tigh, int limit, const string& suffix) {
        if (idx == maxd) return 1;
        if (dp[idx][tigh] != -1) return dp[idx][tigh];

        ll low = 0, high;
        ll suffix_len = suffix.size();

        if (idx >= maxd - suffix_len) {
            ll suffix_idx = idx - (maxd - suffix_len);
            low = high = suffix[suffix_idx] - '0';
        } else {
            high = tigh ? min<ll>(limit, nums[idx] - '0') : limit;
        }

        ll total = 0;
        for (ll digit = low; digit <= high; ++digit) {
            bool new_tight = tigh && (digit == nums[idx] - '0');
            total += valid(nums, idx + 1, maxd, new_tight, limit, suffix);
        }

        return dp[idx][tigh] = total;
    }

    
    ll solve(const string& num, ll dig, int limit, const string& suffix) {
        memset(dp, -1, sizeof(dp));
        ll result = valid(num, 0, dig, true, limit, suffix);
        if (check(num, dig, suffix, limit))
            result--;
        return result;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suffix) {
        ll suf = stoll(suffix);
        string fin = to_string(finish);
        string str = to_string(start - 1);

        ll find = fin.size();
        ll strd = str.size();

        ll tillf = (finish >= suf) ? solve(fin, find, limit, suffix) : 0;
        ll tillstr  = (suf < start) ? solve(str, strd, limit, suffix) : 0;

        return tillf - tillstr;
    }
};