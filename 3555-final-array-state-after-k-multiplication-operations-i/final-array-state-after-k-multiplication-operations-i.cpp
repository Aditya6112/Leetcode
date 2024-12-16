class Solution {
public:
    int findMinIdx(vector<int>& nums){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
        }
        return q.top().second;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int idx=findMinIdx(nums);
            nums[idx]=multiplier*nums[idx];
        }
        return nums;
    }
};