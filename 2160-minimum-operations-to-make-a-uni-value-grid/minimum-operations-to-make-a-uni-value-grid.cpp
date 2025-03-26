class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>vec;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        int target=vec[(vec.size()/2)];
        for(auto num:vec){
            if(num%x!=target%x){
                return -1;
            }else{
                ans+=abs(target-num)/x;
            }
        }
        return ans;
    }
};