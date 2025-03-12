class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            maxi=max(maxi,num);
            for(int j=i+1;j<nums.size();j++){
                num*=nums[j];
                maxi=max(maxi,num);
            }
        }
        return maxi;
    }
};