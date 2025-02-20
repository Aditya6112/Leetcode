class Solution {
public:
    void generate_all_strings(int n,string str,vector<string>& all_strings){
        if(str.size()==n){
            all_strings.push_back(str);
            return;
        }
        generate_all_strings(n,"0"+str,all_strings);
        generate_all_strings(n,"1"+str,all_strings);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<string>all_strings;
        string str="";
        generate_all_strings(n,str,all_strings);
        unordered_set<string>mpp;
        for(auto s:nums){
            mpp.insert(s);
        }
        for(auto it:all_strings){
            if(mpp.find(it)==mpp.end()){
                return it;
            }
        }
        return "";
    }
};