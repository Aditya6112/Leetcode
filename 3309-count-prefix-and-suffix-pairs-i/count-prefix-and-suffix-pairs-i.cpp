class Solution {
public:
    bool isPrefixAndSuffix(string str1,string str2){
        //we have to check str1 is both prefix and suffix of str2
        int str1_s=str1.size();
        int str2_s=str2.size();
        if(str2_s<str1_s)return false;

        //check prefix
        int i=0;
        int j=0;
        while(i<str1_s){
            if(str1[i]!=str2[j]){
                return false;
            }
            i++;
            j++;
        }

        //check suffix
        i=str1_s-1; //last index
        j=str2_s-1; // last index of str2
        while(i>=0){
            if(str1[i]!=str2[j]){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};