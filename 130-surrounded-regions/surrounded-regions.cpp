class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c,vector<vector<int>>& visited,int dirx[],int diry[]){
        visited[r][c]=1;
        for(int k=0;k<4;k++){
            int i=r+dirx[k];
            int j=c+diry[k];
            if(i>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i][j]=='O' && visited[i][j]==0){
                dfs(board,i,j,visited,dirx,diry);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        //directions
        int dirx[]={-1,0,1,0};
        int diry[]={0,1,0,-1};
        //check all the boundries
        vector<vector<int>>visited(m,vector<int>(n,0));
        //first row
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && visited[0][j]!=1){
                dfs(board,0,j,visited,dirx,diry);
            }
        }
        //first col
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && visited[i][0]!=1){
                dfs(board,i,0,visited,dirx,diry);
            }
        }
        //last col
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O' && visited[i][n-1]!=1){
                dfs(board,i,n-1,visited,dirx,diry);
            }
        }
        //last row
        for(int j=0;j<n;j++){
            if(board[m-1][j]=='O' && visited[m-1][j]!=1){
                dfs(board,m-1,j,visited,dirx,diry);
            }
        }

        //now change the board w.r.t visited if visited==1 then dont touch else convert to 'X'

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }else{
                    continue;
                }
            }
        }
    }
};