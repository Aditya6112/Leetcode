class Solution {
public:
    vector<int> partitionLabels(string s) {
        //store last idx of each character
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            char x=s[i];
            mp[x]=i;
        }

        int start=0,end=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            end=max(end,mp[s[i]]);
            if(end==i){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};