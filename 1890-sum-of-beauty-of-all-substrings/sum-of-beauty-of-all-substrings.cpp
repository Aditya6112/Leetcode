class Solution {
public:
    int fn(map<char,int>&mp){
        int small=1e9,large=-1e9;
        for(auto [f,s]:mp){
            small=min(small,s);
            large=max(large,s);
        }
        return (large-small);
    }
    int beautySum(string s) {
        
        int ans=0;
        for(int i=0;i<s.size();i++){
            map<char,int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                if(mp.size()>=2){
                    ans+=fn(mp);
                }
            }
        }
        return ans;
    }
};