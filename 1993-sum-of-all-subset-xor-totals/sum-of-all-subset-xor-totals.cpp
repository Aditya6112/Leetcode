class Solution {
public:
    void generateSubsets(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& subset) {
        if (idx == nums.size()) {
            subset.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[idx]);
        generateSubsets(nums, idx + 1, temp, subset);
        temp.pop_back();

        // Exclude current element
        generateSubsets(nums, idx + 1, temp, subset);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>subset;
        generateSubsets(nums,0,temp,subset);
        int sum=0;
        for (auto it : subset) {
            if (it.empty()) continue;
            int xoor = it[0];
            for (int i = 1; i < it.size(); i++) {
                xoor ^= it[i];
            }
            sum += xoor;
        }
        return sum;
    }
};