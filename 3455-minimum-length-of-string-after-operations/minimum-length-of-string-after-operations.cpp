class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mpp;
        int cnt=0;
        for(auto it:s){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.second%2==0){
                cnt+=2;
            }else{
                cnt+=1;
            }
        }
        return cnt;
    }
};