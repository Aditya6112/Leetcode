class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int n=nums.size();
        int sum=0;
        int maxArr=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];           
            int rem=sum-k; 
            if(mpp.find(rem)!=mpp.end()){
                maxArr+=mpp[rem];
            }
            mpp[sum]++;
        }
        return maxArr;
    }
};