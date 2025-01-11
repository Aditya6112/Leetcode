class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        if(s.size()==k)return true;
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int odd_count=0;
        for(auto it:mpp){
            if(it.second%2!=0){
                odd_count++;
            }
        }
        if(odd_count>k)return false;
        return true;
    }
};