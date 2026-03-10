class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        while (end < nums.size()) {
            sum += nums[end];
            cout << sum << " ";
            while (sum >= target) {
                length = min(length, end - start + 1);
                sum -= nums[start];
                start++;
                if (sum <= 0)
                    sum = 0;
            }
            end++;
        }
        return length==INT_MAX ? 0 : length;
    }
};