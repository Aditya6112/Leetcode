class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        int sIdx=-1;
        int minLen=INT_MAX;
        unordered_map<char,int>mp;
        for(auto ch:t){
            mp[ch]++;
        }
        int cnt=0;
        int i=0;
        for(int j=0;j<m;j++){
            if(mp[s[j]]>0){
                cnt++;
            }
            mp[s[j]]--;
            while(cnt==n){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    sIdx=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)cnt-=1;
                i++;
            }
        }
        return sIdx==-1 ? "" : s.substr(sIdx,minLen);
    }
};