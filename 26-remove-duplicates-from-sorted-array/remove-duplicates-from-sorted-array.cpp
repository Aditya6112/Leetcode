class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>new_nums;
        int prev=nums[0];
        new_nums.push_back(prev);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev){
                continue;
            }else{
                prev=nums[i];
                new_nums.push_back(nums[i]);
            }
        }
        for(int i=0;i<min(nums.size(),new_nums.size());i++){
            nums[i]=new_nums[i];
        }
        return new_nums.size();
    }
};