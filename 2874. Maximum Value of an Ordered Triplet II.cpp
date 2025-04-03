class Solution {
public:
  long long max(const long long &a, const long long &b) {
    if (a > b)
      return a;
    else
      return b;
  }

  long long maximumTripletValue(vector<int> &nums) {
    int sz = nums.size();

    vector<long long> max_pref(sz + 5, -1e9), max_suff(sz + 5, -1e9);

    for (int i = 1; i <= sz; i++) {
      max_pref[i] = max(max_pref[i - 1], nums[i - 1]);
    }
    for (int i = sz; i >= 1; i--) {
      max_suff[i] = max(max_suff[i + 1], nums[i - 1]);
    }

    long long ans = 0;

    for (int i = 2; i < sz; i++) {
      ans = max(ans, (max_pref[i - 1] - nums[i - 1]) * max_suff[i + 1]);
    }

    return ans;
  }
};
