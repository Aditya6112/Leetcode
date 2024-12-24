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
    int bottomUp(string s,int n){
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            }else{
                dp[i]=dp[i+1];
                if(i+1<n){
                    if((s[i]=='1') || (s[i]=='2' && s[i+1]<='6')){
                        dp[i]+=dp[i+2];
                    }
                }
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        int n=s.size();
        int cnt=0;
        vector<int>dp(n+1,-1);
        return bottomUp(s,n);
    }
};