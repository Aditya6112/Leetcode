class Solution {
public:
    void dfs(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& visited,int dirx[], int diry[]){
        visited[r][c]=1;
        //traverse all 4 dirs
        for(int k=0;k<4;k++){
            int i=r+dirx[k];
            int j=c+diry[k];
            if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1 && visited[i][j]==0){
                dfs(grid,i,j,visited,dirx,diry);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //directions
        int dirx[]={-1,0,1,0};
        int diry[]={0,1,0,-1};
        //visited
        vector<vector<int>>visited(m,vector<int>(n,0));
        //first row
        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && visited[0][j]==0){
                dfs(grid,0,j,visited,dirx,diry);
            }
        }
        //first col
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && visited[i][0]==0){
                dfs(grid,i,0,visited,dirx,diry);
            }
        }
        //last row
        for(int j=0;j<n;j++){
            if(grid[m-1][j]==1 && visited[m-1][j]==0){
                dfs(grid,m-1,j,visited,dirx,diry);
            }
        }
        //last col
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1 && visited[i][n-1]==0){
                dfs(grid,i,n-1,visited,dirx,diry);
            }
        }

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};