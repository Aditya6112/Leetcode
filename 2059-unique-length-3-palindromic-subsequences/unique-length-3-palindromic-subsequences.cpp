class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count=0;
        set<char>all_char;
        for(char ch:s){
            all_char.insert(ch);
        }
        //iterate over all char in set and identify palindrome for each char
        for(auto ch:all_char){
            set<char>between_char;
            int i=0;
            int j=s.size()-1;
            while(s[i]!=ch){
                i++;
            }
            while(s[j]!=ch){
                j--;
            }
            for(int k=i+1;k<j;k++){
                between_char.insert(s[k]);
            }
            count+=between_char.size();
        }
        return count;
    }
};