class Solution {
public:
    void bfs(int src,unordered_map<int,list<int>>& adj_List,vector<bool>& visited){
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto nbr:adj_List[frontNode]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
    }
    void dfs(int src,unordered_map<int,list<int>>& adj_List,vector<bool>& visited){
        visited[src]=true;
        for(auto nbr:adj_List[src]){
            if(!visited[nbr])dfs(nbr,adj_List,visited);
        }
    }
    void adjList(vector<vector<int>>& isConnected,unordered_map<int,list<int>>& adj_List){
        int n=isConnected.size();
        int m=isConnected[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adj_List[i].push_back(j);
                    adj_List[j].push_back(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,list<int>> adj_List;
        vector<bool> visited(n,false);
        adjList(isConnected,adj_List);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj_List,visited);
                cnt++;
            }
        }
        return cnt;
    }
};