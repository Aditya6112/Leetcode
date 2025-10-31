class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto num:nums){
            mp[num]++;
        }
        for(auto it:mp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};