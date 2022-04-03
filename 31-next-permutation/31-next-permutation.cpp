class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 1;
    while (i >= 1 && nums[i] <= nums[i - 1]) {
        i--;
    }

    //sort desending
    sort(nums.begin() + i, nums.end());
    if (i == 0) return; //last permutation

	// find first max and swap with i-1 index
    for (int j = i; j < nums.size(); j++)
        if (nums[j] > nums[i - 1]) {
            swap(nums[i - 1], nums[j]);
            break;
        }
  }
};