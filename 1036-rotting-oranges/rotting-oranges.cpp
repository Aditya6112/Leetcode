class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }

        int dirx[] = {0, 1, 0, -1}; // Direction arrays for row
        int diry[] = {1, 0, -1, 0}; // Direction arrays for column
        int time = 0; // Count of rounds/steps needed for rotting

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+dirx[i];
                int ncol=col+diry[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() &&
                    vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                        q.push({{nrow,ncol},t+1});
                        vis[nrow][ncol]=2;
                    }
            }
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && vis[i][j]!=2)return -1;
            }
        }
        return time;
    }
};
