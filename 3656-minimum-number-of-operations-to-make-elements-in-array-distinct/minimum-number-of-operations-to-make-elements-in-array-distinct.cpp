class Solution {
public:
    bool isDistinct(vector<int>& nums,int start){
        unordered_set<int> mp;
        for (int i = start; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                return false;
            }
            mp.emplace(nums[i]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 3, ans++) {
            if (isDistinct(nums,i)) {
                return ans;
            }
        }
        return ans;
    }
};