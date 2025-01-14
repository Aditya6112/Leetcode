class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>res;
        for(int i=0;i<A.size();i++){
            unordered_map<int,int>mpp;
            for(int j=0;j<=i;j++){
                mpp[A[j]]++;
                mpp[B[j]]++;
            }
            int cnt=0;
            for(auto it:mpp){
                if(it.second%2==0)cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};