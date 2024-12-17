class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26,0);
        string ans="";
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        
        priority_queue<char>maxH;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                maxH.push(i+'a');
            }
        }

        while(!maxH.empty()){
            char top=maxH.top();
            maxH.pop();
            int limit=min(freq[top-'a'],repeatLimit);
            ans.append(limit,top);
            freq[top-'a']-=limit;
            if(freq[top-'a']!=0){
                if(maxH.empty())break;
                char next_top=maxH.top();
                maxH.pop();
                ans.push_back(next_top);
                freq[next_top-'a']--;

                if(freq[next_top-'a']>0)maxH.push(next_top);
                maxH.push(top);
            }
        }
        return ans;
    }
};