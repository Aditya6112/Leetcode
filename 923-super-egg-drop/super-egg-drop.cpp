vector<vector<int>>dp(101,vector<int>(10001,-1));
class Solution {
public:
    int superEggDrop(int k, int n) {
        if(n==0 || n==1)return n;
        if(k==1)return n;
        if(dp[k][n]!=-1)return dp[k][n];

        int mini=INT_MAX;
        int start=0,end=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            int low,high;
            if(dp[k-1][mid-1]!=-1){
                low=dp[k-1][mid-1];
            }else{
                low=superEggDrop(k-1,mid-1);
                dp[k-1][mid-1]=low;
            }
            if(dp[k][n-mid]!=-1){
                high=dp[k][n-mid];
            }else{
                high=superEggDrop(k,n-mid);
                dp[k][n-mid]=high;
            }
            if(low>high){
                end=mid-1;
            }else{
                start=mid+1;
            }
            int temp=1+max(low,high);
            mini=min(mini,temp);
        }
        return dp[k][n]=mini;
    }
};