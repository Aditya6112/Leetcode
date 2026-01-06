class Solution {
public:
    bool solve(string s,string str, vector<string>& wordDict,int idx,unordered_set<string>& mp,vector<int>& dp){
        if(idx>=s.size()){
            return true;
        }
        if(mp.find(s)!=mp.end()){
            return true;
        }
        if(dp[idx]!=-1)return dp[idx];
        for(int len=1;len<=s.size();len++){
            str=s.substr(idx,len);
            if(mp.find(str)!=mp.end() && solve(s,str,wordDict,len+idx,mp,dp)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>mp;
        vector<int>dp(s.size()+1,-1);
        string str="";
        for(auto w:wordDict){
            mp.insert(w);
        }
        return solve(s,str,wordDict,0,mp,dp);
    }
};