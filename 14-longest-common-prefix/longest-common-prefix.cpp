class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];
        sort(strs.begin(),strs.end());
        string ans="";
        string prev=strs[0];
        string curr=strs[strs.size()-1];
        int j=0;
        while(j<min(prev.size(),curr.size())){
            if((prev[j]==curr[j])){
                ans.push_back(prev[j]);
                j++;
            }else{
                break;
            }
        }
        return ans;
    }
};