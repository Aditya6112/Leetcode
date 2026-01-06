class Solution {
public:
    int solve(string s,string str,int idx,unordered_set<string>& mp,vector<int>& dp){
        if(idx==s.size()){
            return 1;
        }
        if(idx>s.size()){
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int sum=0;
        for(int len=1;len<=s.size();len++){
            str=s.substr(idx,len);
            if(mp.find(str)!=mp.end()){
                sum+=solve(s,str,idx+len,mp,dp);
            }
        }
        return dp[idx]=sum;
    }
    int numDecodings(string s) {
        unordered_set<string>mp;
        string str="";
        vector<int>dp(s.size()+1,-1);
        for(int i=1;i<=26;i++){
            mp.insert(to_string(i));
        }
        return solve(s,str,0,mp,dp);
    }
};