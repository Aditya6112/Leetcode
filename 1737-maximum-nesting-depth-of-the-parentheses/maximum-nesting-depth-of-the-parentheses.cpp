class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int cnt=0;
        for(auto it:s){
            if(it=='('){
                cnt++;
                maxi=max(maxi,cnt);
            }else if(it==')'){
                maxi=max(maxi,cnt);
                cnt--;
            }
        }
        return maxi;
    }
};