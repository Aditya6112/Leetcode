class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        unordered_map<char,int>mp;
        int cnt=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()==3){
                cnt+=s.size()-j;
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};