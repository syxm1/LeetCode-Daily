class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int ret = 0, sz = nums.size();
    for (int mask = 0; mask < (1 << sz); mask++) {
      int cur = 0;
      for (int i = 0; i < sz; i++) {
        if ((1 << i) & mask) {
          cur = (cur ^ nums[i]);
        }
      }
      ret += cur;
    }
    return ret;
  }
};
