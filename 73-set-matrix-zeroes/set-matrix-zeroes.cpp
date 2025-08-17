class Solution {
public:
    void setRowColToZero(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>& visited){
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][c]!=0){
                matrix[i][c]=0;
                visited[i][c]=1;
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[r][j]!=0){
                matrix[r][j]=0;
                visited[r][j]=1;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(visited[i][j]==0){
                        setRowColToZero(matrix,i,j,visited);
                    }
                }
            }
        }
    }
};