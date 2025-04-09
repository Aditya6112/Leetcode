class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>mp;
        for(auto it:nums){
            if(it<k){
                return -1;
            }else if(it>k){
                mp.insert(it);
            }
        }
        return mp.size();
    }
};