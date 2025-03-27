class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        int totalFreq = 0;
        for (int num : nums) {
            if (num == candidate) {
                totalFreq++;
            }
        }
        
        if (totalFreq * 2 <= n) {
            return -1;
        }
        int leftFreq = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) {
                leftFreq++;
            }
            
            int rightFreq = totalFreq - leftFreq;
            if (leftFreq * 2 > (i + 1) && rightFreq * 2 > (n - i - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};
