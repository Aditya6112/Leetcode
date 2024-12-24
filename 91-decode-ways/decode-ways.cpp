class Solution {
public:
    int solve(string s,int idx,int n,vector<int>& dp){
        if(idx==n)return 1;
        if(s[idx]=='0')return 0;
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int result=solve(s,idx+1,n,dp);
        if(idx+1<n){
            if((s[idx]=='1') || (s[idx]=='2' && s[idx+1]<='6')){
                result+=solve(s,idx+2,n,dp);
            }
        }
        return dp[idx]=result;
    }
    int numDecodings(string s) {
        int n=s.size();
        int cnt=0;
        vector<int>dp(n+1,-1);
        return solve(s,0,n,dp);
    }
};