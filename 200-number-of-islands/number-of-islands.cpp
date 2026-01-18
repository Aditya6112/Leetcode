class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j,int m,int n,int dirx[],int diry[]){
        visited[i][j]=1;
        for(int d=0;d<4;d++){
            int r=i+dirx[d];
            int c=j+diry[d];

            if(r>=0 && r<m && c>=0 && c<n){
                if(grid[r][c]=='1' && !visited[r][c]){
                    dfs(grid,visited,r,c,m,n,dirx,diry);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dirx[]={-1,0,1,0};
        int diry[]={0,1,0,-1};
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(grid,visited,i,j,m,n,dirx,diry);
                }
            }
        }
        return count;
    }
};