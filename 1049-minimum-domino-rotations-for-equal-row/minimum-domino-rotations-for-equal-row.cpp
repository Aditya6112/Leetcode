class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int ans=INT_MAX;
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(tops[i]);
            st.insert(bottoms[i]);
        }
        for(auto it:st){
            int cnt1=0;
            int cnt2=0;
            for(int i=0;i<n;i++){
                if(cnt1!=-1){
                    if(tops[i]==it){
                        // continue;
                    }else if(bottoms[i]==it){
                        cnt1++;
                    }else{
                        cnt1=-1;
                    }
                }
                
                if(cnt2!=-1){
                    if(bottoms[i]==it){
                        // continue;
                    }else if(tops[i]==it){
                        cnt2++;
                    }else{
                        cnt2=-1;
                    }
                }

                if(cnt1==-1 && cnt2==-1)break;
            }
            if(cnt1!=-1)ans=min(ans,cnt1);
            if(cnt2!=-1)ans=min(ans,cnt2);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};