class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum_total = accumulate(begin(nums), end(nums), 0);
        unordered_map<int,int> numCnt;
        int ans=INT_MIN;
        for(auto num:nums){
            numCnt[num]++;
        }
        for(auto num:nums){
            numCnt[num]--;
            int sum=sum_total-num;
            if(sum%2==0 && numCnt[sum/2]>0)ans=max(ans,num);
            numCnt[num]++;
        }
        return ans;
    }
};