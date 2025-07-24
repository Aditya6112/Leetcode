class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1){
            return ans;
        }
        ans.push_back({1,1});
        if(numRows==2){
            return ans;
        }
        for(int i=3;i<=numRows;i++){
            vector<int>temp;
            temp.push_back(1);
            vector<int>prev=ans.back();
            for(int i=0;i<prev.size()-1;i++){
                int sum=prev[i]+prev[i+1];
                temp.push_back(sum);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};