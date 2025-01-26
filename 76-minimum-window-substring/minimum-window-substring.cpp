class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        unordered_map<char,int>mp;
        for(auto c:t){
            mp[c]++;
        }
        int i=0,j=0;
        int requiredCount=t.size();
        int minWindowSize=INT_MAX;
        int start_i=0;
        while(j<s.size()){
            char ch=s[j];
            if(mp[ch]>0){
                requiredCount--;
            }
            mp[ch]--;//we found one character then decrese the count in map

            //if required count is 0 then try to shrink the window
            while(requiredCount==0){
                int currWindowSize=j-i+1;
                if(currWindowSize<minWindowSize){
                    minWindowSize=currWindowSize;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i,minWindowSize);
    }
};