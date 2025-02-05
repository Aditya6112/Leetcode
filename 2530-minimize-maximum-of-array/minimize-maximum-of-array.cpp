class Solution {
public:
    bool isValid(vector<int>& nums,int maxi_num){
        vector<long long> arr(begin(nums),end(nums));
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>maxi_num){
                return false;
            }else{
                long long buffer=maxi_num-arr[i];
                arr[i+1]-=buffer;
            }
        }
        return arr[arr.size()-1]<=maxi_num;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(nums,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};