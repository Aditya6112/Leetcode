class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==target){
                return m;
            }
            //left part is sorted
           if(nums[s]<=nums[m]){
                if(nums[s]<=target && nums[m]>=target){
                    e=m-1;
                }else{
                    s=m+1;
                }
           }
           else{
                if(nums[e]>=target && nums[m]<=target){
                    s=m+1;
                }else{
                    e=m-1;
                }
           }
        }
        return -1;
    }
};