class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int ans=INT_MIN;
        for(int i=1;i<n;i++){

            int zero_cnt=0;
            for(int j=0;j<i;j++){
                if(s[j]=='0'){
                    zero_cnt++;
                }
            }

            int one_cnt=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1'){
                    one_cnt++;
                }
            }
            
            ans=max(ans,(zero_cnt+one_cnt));
        }
        return ans;
    }
};