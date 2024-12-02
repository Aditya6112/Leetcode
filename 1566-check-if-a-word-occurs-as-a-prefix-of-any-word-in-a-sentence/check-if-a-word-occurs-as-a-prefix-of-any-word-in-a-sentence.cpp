class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<pair<string,int>>mpp;
        int words_count=1;
        string temp="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' '){
                temp+=sentence[i];
            }else{
                mpp.push_back({temp,words_count});
                words_count++;
                temp="";
            }
        }
        //push the remaining word in temp
        if(!temp.empty())mpp.push_back({temp,words_count});
        
        for(auto it:mpp){
            int pos=it.first.find(searchWord);
            if(pos==0){
                return it.second;
            }
        }

        return -1;
    }
};