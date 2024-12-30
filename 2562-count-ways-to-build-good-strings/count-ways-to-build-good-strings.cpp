class Solution {
public:
    int dp[100001];
    int MOD=1000000007;
    int solve(int low,int high,int zero,int one,int len){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        int count=0;
        if(len>=low && len<=high)count++;
        count+=solve(low,high,zero,one,len+zero);
        count+=solve(low,high,zero,one,len+one);
        return dp[len]=count%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        int len=0;
        return solve(low,high,zero,one,len);
    }
};