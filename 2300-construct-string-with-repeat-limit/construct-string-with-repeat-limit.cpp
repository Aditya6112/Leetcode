class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26,0);
        string ans="";
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int i=25;
        while(i>=0){
            if(freq[i]==0){
                i--;
                continue;
            }
            char ch=i+'a';
            int limit=min(freq[i],repeatLimit);
            ans.append(limit,ch);
            freq[i]-=limit;

            if(freq[i]!=0){
                int j=i-1;
                while(j>=0 && freq[j]==0){
                    j--;
                }

                if(j<0){
                    break;
                }
                ans.push_back(j+'a');
                freq[j]--;
            }
        }
        return ans;
    }
};