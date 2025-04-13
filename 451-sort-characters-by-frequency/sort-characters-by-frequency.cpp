class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans="";
        for(auto it:s){
            mp[it]++;
        }

        priority_queue<pair<int,char>>maxH;
        for(auto it:mp){
            maxH.push({it.second,it.first});
        }

        while(!maxH.empty()){
            auto top=maxH.top();
            maxH.pop();
            while(top.first--){
                ans+=top.second;
            }
        }
        return ans;
    }
};