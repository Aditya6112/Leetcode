class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=LONG_MIN;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    long long solve=(long long)(nums[i]-nums[j])*nums[k];
                    maxi=max(maxi,solve);
                }
            }
        }
        return maxi<0 ? 0 : maxi;
    }
};