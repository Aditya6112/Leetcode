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

        int remain=numRows-2;
        int idx=1;
        while(remain--){
            vector<int>temp=ans[idx];
            vector<int>new_arr;
            new_arr.push_back(1);
            int i=0,j=1;
            while(j<temp.size()){
                int sum=temp[i]+temp[j];
                new_arr.push_back(sum);
                i++;
                j++;
            }
            new_arr.push_back(1);
            ans.push_back(new_arr);
            idx++;
        }
        return ans;
    }
};