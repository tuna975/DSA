class Solution {
public:
  bool solve(vector<int>& nums, vector<vector<int>>& queries, int k) {
    int n = nums.size(), sum = 0;
    vector<int> a(n + 1);

    for (int i = 0; i < k; i++) {
      int s = queries[i][0], e = queries[i][1], val = queries[i][2];
      a[s] += val;
      a[e + 1] -= val;
    }

    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum < nums[i]) return false;
    }
    return true;
  }

  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), l = 0, r = queries.size(), ans = -1;
    if (!solve(nums, queries, r)) return -1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (solve(nums, queries, mid)) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};