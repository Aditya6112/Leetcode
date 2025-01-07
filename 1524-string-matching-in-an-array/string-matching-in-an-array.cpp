class Solution {
public:
    static bool cmp(string A,string B){
        return A.size()<B.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<string>res;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(words[j].find(words[i])!=string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};