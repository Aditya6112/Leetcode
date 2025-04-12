class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            string temp=goal;
            reverse(temp.begin(),temp.begin()+i);
            reverse(temp.begin()+i,temp.end());
            reverse(temp.begin(),temp.end());
            cout<<temp<<endl;
            if(s==temp){
                return true;
            }
        }
        return false;
    }
};