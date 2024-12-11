class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; ++j) {
            while (nums[j] - nums[i] > 2 * k) {
                i++;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
