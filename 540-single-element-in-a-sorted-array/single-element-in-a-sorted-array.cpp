class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                return nums[i];
            }
            i+=2;
            j+=2;
        }
        return 0;
    }
};