class Solution {
public:
    int b_search(vector<int>& nums,int target){
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==target){
                return true;
            }else if(nums[m]>target){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return false;
    }
    int search(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }
        sort(nums.begin(),nums.end());
        if(b_search(nums,target)){
            return mpp[target];
        }
        return -1;
    }
};